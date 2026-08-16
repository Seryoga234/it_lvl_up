#include <iostream>  // ; meow/мяу
#include "menu_function.h"
#include "time.h"
#include <ctime>
#include "sqlite3.h"


int main() {   // маркер для хакера , л - логика
	std::cout << "SQLite Version: " << sqlite3_libversion() << std::endl;
	menu();

	time();

	return 0;
}