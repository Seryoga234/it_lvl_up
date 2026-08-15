#include "time.h"
#include <iostream>
#include <ctime>

char letter;

/*int timer() {

	volatile int f = 4;
	std::time_t start = std::time(nullptr); //std::time_t start - коробка для переменной. std::time() - сомтрит на дату устройства

	std::time_t end = std::time(nullptr);

	switch (letter) {
	
	}


	int a;

	for (a = start; a < end; a++)
	{

	}
	return 0;

}*/

/*int ended() {
	std::time_t end = std::time(nullptr);
	return end;
}
int started() {
	std::time_t start = std::time(nullptr);
	int st[1] = { start };
	return st[1];
}*/


void time() { // тупо чтоб выполнить задачу.

	int result;
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

	// double difftime( std::time_t time_end, std::time_t time_start );
	// std::time_t time( std::time_t* arg );
	//std::gmtime();

	std::cout << " If you wanna Start press  ' -- S -- '\n";
	std::cout << " If you wanna End timer press  ' -- E -- '\n";
	std::cout << " If you wanna go Out of timer press  ' -- O -- '\n";

	//int a = started();
	//int b = ended();
	std::time_t start = 0;
	std::time_t end = 0;
	int seconds;
	do
	{
		std::cin >> letter;
		switch (letter) {
		case 's':
		case 'S': 
			std::cout << " Timer is Strat!\n";
			start = std::time(nullptr);
			std::cout << start << std::endl;
			break;
		 
		case 'e':
		case 'E':  
			std::cout << " Timer is End! ";
			end = std::time(nullptr);
			std::cout << end << "\n";
			seconds = std::difftime(end, start);
			std::cout << seconds;
			/*for (int a = started(), b = ended(); a <= b;)
			{
				std::cout << (result = b - a)<< std::endl;
			}*/

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
	