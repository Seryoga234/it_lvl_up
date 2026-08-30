#include <iostream>  // ; meow/мяу
#include "menu_function.h"
#include "time.h"
#include <ctime>
#include "sqlite3.h"
#include "notes_memory.h"



int main() {   // маркер для хакера , л - логика
	std::cout << "SQLite Version: " << sqlite3_libversion() << std::endl;

	notes_m();

	menu();

	time();

	return 0;
}