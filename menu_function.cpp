#include "menu_function.h"
#include <iostream>

void menu() {

	std::cout << " -----====== Welcome to your LEVEL UP ======----- " << std::endl;

	std::cout << " MENU\n 1. Work\n 2. My Projects\n 3. Study\n 4. Import Data" << std::endl;

	int choice;
	;

	do
	{
		std::cin >> choice;
		switch (choice) {

		case 1:
			std::cout << " 1. Work Time\n 2. Notes\n";
			do
			{
				std::cin >> choice;
				switch (choice) {
				case 1:
					// open function #1 (Work Time).
					std::cout << " 1111\n";
					break;
				case 2:
					// open function #2 (Notes).
					std::cout << " 2222\n";
					break;
				}
			} while (choice < 1 || choice > 2);

			break;
		case 2:
			std::cout << " 1. Calendar\n";
			do
			{
				switch (choice) {
				case 1:
					std::cout << "1.1.1.1\n";
					break;
				}
			} while (choice < 1 || choice > 1);
			break;
		case 3:
			std::cout << " 1. Notes for Language\n 3. Discoveries";

			do
			{
				switch (choice) {
				case 1:
					std::cout << "111";
					break;
				case 2:
					std::cout << "222";
					break;
				}
			} while (choice < 1 || choice > 2);

			break;
		case 4:
			std::cout << "Import Files";
			do
			{
				switch (choice) {
				case 1:
					std::cout << "11";
					break;
				}
			} while (choice < 1 || choice > 4);
			break;
		}
	} while (choice < 1 || choice > 4);

}