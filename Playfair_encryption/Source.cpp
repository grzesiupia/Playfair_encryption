#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ios>
#include <limits>
#include <conio.h>

struct Letters {
	char letter;
	int x;
	int y;
};

std::string noRepeats(std::string text) {
	std::string withoutRepeats;
	bool repeat = false;
	withoutRepeats.push_back(text[0]);

	for (int i = 0; i < text.size(); i++) {
		repeat = false;
		for (int j = 0; j < withoutRepeats.size(); j++) {
			if (text[i] == withoutRepeats[j]) {
				repeat = true;
			}
			else {
				repeat = false;
			}
		}
		if (repeat == false) {
			withoutRepeats.push_back(text[i]);
		}
	}

	return withoutRepeats;
}

std::string toUpper(std::string text) {
	std::string upper;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] >= 97 && text[i] <= 122) {
			upper.push_back(text[i] - 32);
		}
		else if(text[i] >= 65 && text[i] <= 90){
			upper.push_back(text[i]);
		}
	}

	return upper;
}

std::vector<char>alphabet() {
	std::vector<char>a;
	int ascii = 65;
	for (int i = 0; i < 25; i++) {
			if (ascii == 81) {
				ascii += 1;
			}
			a.push_back(ascii);
			ascii += 1;
		
	}
	return a;
}

std::vector<char>tableMaker(std::string keyword) {
	std::vector<char>a = alphabet();
	for (int i = keyword.size() - 1; i >= 0; i--) {
		for (int j = 0; j < 25; j++) {
			if (keyword[i] == a[j]) {
				a.erase(a.begin() + j);
				a.insert(a.begin(), keyword[i]);
			}
		}
	}
			
			for (int i = 0; i < a.size(); i++) {
				std::cout << a[i] << " ";
			}
			std::cout << std::endl;
			
	return a;
}

std::vector<Letters> toStruct(std::vector<char>table) {
	std::vector<Letters>p;
	Letters Letter;
	for (int i = 0; i < table.size(); i++) {
		Letter.letter = table[i];
		Letter.x = i % 5;
		Letter.y = int(i / 5);
		p.push_back(Letter);
		//std::cout << p[i].letter << " (" << p[i].x<< ", " << p[i].y << ")" << std::endl;
	}
	return p;
}

std::string codeEncryption(std::vector<Letters> l, std::string text) {
	std::vector<Letters>toCode;
	Letters char1, char2;
	std::string code = "";
	for (int i = 0; i < text.size() - 1; i++) {
		if ((i < text.size() - 1) && text[i] == text[i + 1]) {
			text.insert((i+1), "X");
		}
	}
	if (text.size() % 2 != 0 || text.size() == 1) {
		text.push_back('X');
	}
	std::cout << text << std::endl;

	for (int i = 0; i < text.size(); i++) {
		for (int j = 0; j < l.size(); j++) {
			if (text[i] == l[j].letter) {
				toCode.push_back(l[j]);
			}
		}
		//std::cout << toCode[i].letter << " " << toCode[i].x << ", " << toCode[i].y << std::endl;
	}

	for (int i = 0; i < toCode.size(); i += 2) {
		
		std::cout << toCode[i].letter << toCode[i + 1].letter << "-> ";
		
		if (toCode[i].y != toCode[i + 1].y && toCode[i].x != toCode[i + 1].x) {
			for (int j = 0; j < l.size(); j++) {
				if (toCode[i].x == l[j].x && toCode[i + 1].y == l[j].y) {
					char1 = l[j];
				}
				if (toCode[i + 1].x == l[j].x && toCode[i].y == l[j].y) {
					char2 = l[j];
				}			
			}
			code.push_back(char1.letter);
			code.push_back(char2.letter);
			/*
			if (char1.x < char2.x) {
				code.push_back(char1.letter);
				code.push_back(char2.letter);
			}
			else {
				code.push_back(char2.letter);
				code.push_back(char1.letter);
			}
			*/
		}
		if (toCode[i].y == toCode[i + 1].y) {
			for (int j = 0; j < l.size(); j++) {
				if (toCode[i].letter == l[j].letter) {
					if (l[j].x == 4) {
						code.push_back(l[j - 4].letter);
					}
					else {
						code.push_back(l[j + 1].letter);
					}
					
				}
			}
			for (int j = 0; j < l.size(); j++) {
				if (toCode[i + 1].letter == l[j].letter) {
					if (l[j].x == 4) {
						code.push_back(l[j - 4].letter);
					}
					else {
						code.push_back(l[j + 1].letter);
					}

				}
			}
		}
		if (toCode[i].x == toCode[i + 1].x) {
			for (int j = 0; j < l.size(); j++) {
				if (toCode[i].letter == l[j].letter) {
					if (l[j].y == 4) {
						code.push_back(l[j - 20].letter);
					}
					else {
						code.push_back(l[j + 5].letter);
					}

				}
			}
			for (int j = 0; j < l.size(); j++) {
				if (toCode[i + 1].letter == l[j].letter) {
					if (l[j].y == 4) {
						code.push_back(l[j - 20].letter);
					}
					else {
						code.push_back(l[j + 5].letter);
					}

				}
			}
		}
		std::cout << code[i] << code[i+1] << std::endl;
	}

	std::cout << code << std::endl;

	return code;
}

std::string codeDecryption(std::vector<Letters> l, std::string text) {
	std::vector<Letters>toCode;
	Letters char1, char2;
	std::string code = "";

	std::cout << text << std::endl;

	for (int i = 0; i < text.size(); i++) {
		for (int j = 0; j < l.size(); j++) {
			if (text[i] == l[j].letter) {
				toCode.push_back(l[j]);
			}
		}
		//std::cout << toCode[i].letter << " " << toCode[i].x << ", " << toCode[i].y << std::endl;
	}

	for (int i = 0; i < toCode.size(); i += 2) {

		std::cout << toCode[i].letter << toCode[i + 1].letter << "-> ";

		if (toCode[i].y != toCode[i + 1].y && toCode[i].x != toCode[i + 1].x) {
			for (int j = 0; j < l.size(); j++) {
				if (toCode[i].x == l[j].x && toCode[i + 1].y == l[j].y) {
					char1 = l[j];
				}
				if (toCode[i + 1].x == l[j].x && toCode[i].y == l[j].y) {
					char2 = l[j];
				}
			}

			code.push_back(char1.letter);
			code.push_back(char2.letter);
			/*
			if (char1.x > char2.x) {
				code.push_back(char1.letter);
				code.push_back(char2.letter);
			}
			else {
				code.push_back(char2.letter);
				code.push_back(char1.letter);
			}
			*/
		}
		if (toCode[i].y == toCode[i + 1].y) {
			for (int j = 0; j < l.size(); j++) {
				if (toCode[i].letter == l[j].letter) {
					if (l[j].x == 0) {
						code.push_back(l[j + 4].letter);
					}
					else {
						code.push_back(l[j - 1].letter);
					}

				}
			}
			for (int j = 0; j < l.size(); j++) {
				if (toCode[i + 1].letter == l[j].letter) {
					if (l[j].x == 0) {
						code.push_back(l[j + 4].letter);
					}
					else {
						code.push_back(l[j - 1].letter);
					}

				}
			}
		}
		if (toCode[i].x == toCode[i + 1].x) {
			for (int j = 0; j < l.size(); j++) {
				if (toCode[i].letter == l[j].letter) {
					if (l[j].y == 0) {
						code.push_back(l[j + 20].letter);
					}
					else {
						code.push_back(l[j - 5].letter);
					}

				}
			}
			for (int j = 0; j < l.size(); j++) {
				if (toCode[i + 1].letter == l[j].letter) {
					if (l[j].y == 0) {
						code.push_back(l[j + 20].letter);
					}
					else {
						code.push_back(l[j - 5].letter);
					}

				}
			}
		}
		std::cout << code[i] << code[i + 1] << std::endl;
	}

	std::cout << code << std::endl;

	return code;
}

void menu() {
	bool exit = false;
	std::string keyword, text;
	do {
		system("cls");
		std::cout << "1. Encrypt text\n" << "2. Decrypt text\n" << "x. To exit\n";
		switch (_getch()) {
		case '1': {
			system("cls");
			std::cout << "Write your keyword: ";
			std::cin >> keyword;
			std::cout << "Write your text to encrypt: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, text);
			text = toUpper(text);
			keyword = noRepeats(toUpper(keyword));
			codeEncryption(toStruct(tableMaker(keyword)), text);
			system("pause");
			break;
		}
		case '2': {
			system("cls");
			std::cout << "Write your keyword: ";
			std::cin >> keyword;
			std::cout << "Write your text to decrypt: ";
			std::cin >> text;
			if (text.size() % 2 != 0) {
				std::wcout << "Code is not valid. Please try again.\n";
				system("pause");
				break;
			}
			text = toUpper(text);
			keyword = noRepeats(toUpper(keyword));
			codeDecryption(toStruct(tableMaker(keyword)), text);
			system("pause");
			break;
		}
		case 'x': {
			exit = true;
			break;
		}
		}
	} while (exit == false);
}

int main() {
	menu();
	return 0;
}