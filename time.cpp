#include "time.h"
#include <iostream>
#include <ctime>

void time() { // тупо чтоб выполнить задачу.


	struct tm {

		int tm_sec;
		int tm_min;
		int tm_hour;
		int tm_mday;
		int tm_mon;
		int tm_year;
		int tm_wday;
		int tm_yday;
		int tm_isdst;

	};

	// difftime = time_beg time_end
	//std::gmtime();

	char letter;

	std::cout << " If you wanna start press '-- S --'\n";
	do
	{
		std::cin >> letter;
		switch (letter) {
		case 's':
		case 'S':
			std::cout << " Timer is Strat!\n";
			break;
		case 'e':
		case 'E':
			std::cout << " Timer is End!\n";
			break;
		default:
			std::cout << " Wrong letter! Try again...\n";
			break;
		}

	} while (letter != 'S' && letter != 's' && letter != 'E' && letter != 'e');



}