#include "Utils.h"
#include <iostream>
#include <cctype>

char GetCharachter(const char* prompt, const char* error, const char validInput[], int validInputlenght) {
	char input;
	bool failure;
	do {
		const int IGNORECHARS = 256;


		failure = false;
		std::cout << prompt;
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORECHARS, '\n');
			std::cout << error << std::endl;
			failure = true;



		}
		else {
			std::cin.ignore(IGNORECHARS, '\n');
			if (isalpha(input)) {
				input = tolower(input);
				for (int i = 0; i < validInputlenght; i++) {
					if (validInput[i] == input) {
						return input;
					}
				}
			}
			else {
				std::cout << error << std::endl;
				failure = true;
			}
		}
	} while (failure);
	return input;
}
char GetCharacter(const char* prompt, const char* error) {
	char input;
	const int IGNORECHARS = 256;
	bool failure;
	do {
		failure = false;
		std::cout << prompt;
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORECHARS, '\n');
			std::cout << error << std::endl;
			failure = true;

		}
		else {
			std::cin.ignore(IGNORECHARS, '\n');
			if (isalpha(input)) {
				input = tolower(input);
			}
			else {
				std::cout << error << std::endl;
				failure = true;
			}

		}

	} while (failure);
	return input;
}