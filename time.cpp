#include "time.h"
#include <iostream>
#include <ctime>
#include "sqlite3.h"

char letter;


void time() { // тупо чтоб выполнить задачу.

	int result;

	int sec;
	int min;
	int hour;

	std::time_t start = 0;
	std::time_t end = 0;
	int seconds;
	do
	{
		std::cout << " If you wanna Start press  ' -- S -- '\n";
		std::cout << " If you wanna go Out of timer press  ' -- O -- '\n";
		std::cin >> letter;
		switch (letter) {
		case 's':
		case 'S':
			std::cout << " Timer is Strat!\n";
			start = std::time(nullptr);
			std::cout << start << std::endl;
			std::cout << " If you wanna End timer press  ' -- E -- '\n";
			std::cin >> letter;
			switch (letter) {

			case 'e':
			case 'E':
				std::cout << " Timer is End! ";
				end = std::time(nullptr);
				std::cout << end << "\n";
				seconds = std::difftime(end, start);
				min = seconds / 60;
				sec = seconds % 60;
				hour = seconds / 3600;
				std::cout << " Seconds: " << sec << " Minutes: " << min << " Hours: " << hour << std::endl;
				break;
			}
			break;

		case 'o':
		case 'O':
			std::cout << "Exit...\n";
			break;

		default:
			std::cout << " Wrong letter! Try again...\n";
			break;
		}

	} while (letter != 'o' && letter != 'O');
}
		//while (letter != 'S' && letter != 's' && letter != 'E' && letter != 'e');
	