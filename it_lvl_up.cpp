#include <iostream>  // ; meow/мяу
#include "menu_function.h"
#include "time.h"
#include <ctime>
#include "sqlite3.h"
#include "notes_memory.h"
#include <string>
#include <fstream>


std::string content() {

	std::string c;
	std::cout << " Enter Content\n";
	std::getline(std::cin, c);
	return c;
}


/*delete userSymb;
			userSymb = nullptr;




			std::fstream myFile(title + ".txt", std::ios::in | std::ios::out | std::ios::app);
			
			myFile.open(title + ".txt");
			std::cout << title;

			std::string line;
			std::getline(myFile, title);
			if (myFile.is_open())
			{
				std::cout << " Откртие: " << title << ".txt\n";
			}*/




int main() {   // маркер для хакера , л - логика

	setlocale(LC_ALL, ".UTF-8");

	sqlite3* db = nullptr;

	std::string noteTitle;
	std::string noteContent;

	//std::cout << " Enter title\n";
	//std::getline(std::cin, noteTitle);

	std::cout << " Do you wanna Create or Existing file\n";
	std::cout << " Press ' 1 'to Create\n Press ' 2 ' to Existing file\n";

	int userSymb;
	std::cin >> userSymb;

	do
	{
		
		
		if (userSymb == 1)
		{

			if (sqlite3_open("note_memory.db", &db) != SQLITE_OK) {  // sqlite3_open - Открываем файл , строчка как if (проверяет)
				// SQLITE_OK - означает, что операция прошла успешно
				std::cerr << "Не удалось открыть или создать файл базы данных!" << std::endl; // std::cerr
				return 1;
			}
			
			std::string createTableSQL =
				"CREATE TABLE IF NOT EXISTS notes ("
				"id INTEGER PRIMARY KEY AUTOINCREMENT," // AUTOINCREMENT сам будет ставить 1, 2, 3...
				"title TEXT NOT NULL,"   // Сюда пишем заголовок. NOT NULL - чтоб пусты не сохранял
				"content TEXT NOT NULL"  // Сюда пишем гигантский текст проекта
				");";

			// sqlite3_exec(sql создает(callback) , sql шаг(arg) , sql завершение(errmsg)). sqlite3_exec - функция-«обертка»
			sqlite3_exec(db, createTableSQL.c_str(), nullptr, nullptr, nullptr);  // createTableSQL - команда создания таблицы
			// sqlite3_exec - собирает таблицу

			std::cout << " Введите название Заметки\n";
			std::getline(std::cin, noteTitle);

			std::cout << " Заметка:\n" << noteTitle << std::endl;
			std::getline(std::cin, noteContent);

			std::string insertSQL = "INSERT INTO notes (title) VALUES (?);"; // VALUES (?). ' ? ' - знако вопроса выступает в роли заглушки
			sqlite3_stmt* stmt = nullptr; // sqlite3_stmt - это как контейнер (структура) 
			// внутри sqlite3_stmt - sqlite3_prepare_v2(Сборка коробки) , sqlite3_bind_text(Загрузка в к...) , sqlite3_step(Запуск к...) , sqlite3_finalize

			if (sqlite3_prepare_v2(db, insertSQL.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
				// В первый знак вопроса (1) пихаем НАЗВАНИЕ
				sqlite3_bind_text(stmt, 1, noteTitle.c_str(), -1, SQLITE_STATIC); //для сохранения. 1 это номер колонки (title)
				// std::ofstream myFile(noteTitle); ////////////////
				if (sqlite3_step(stmt) == SQLITE_DONE) {
					std::ofstream myFile(noteTitle + ".txt");
				}
				
				
				sqlite3_finalize(stmt); // Убрали мусор из оперативки

			}




			std::ofstream myFile(noteTitle + ".txt");
			std::cout << "fasds\n";


		}
		else if (userSymb == 2)
		{
			sqlite3_stmt* stmt = nullptr;
			// 5. ШАГ ТРЕТИЙ: Читаем все заметки из файла (SELECT)
			std::string selectSQL = "SELECT id, title, content FROM notes;";

			std::string selectSQL = "SELECT id, title, content FROM notes;";

			if (sqlite3_prepare_v2(db, selectSQL.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
				while (sqlite3_step(stmt) == SQLITE_ROW) {
					int id = sqlite3_column_int(stmt, 0);
					const unsigned char* title = sqlite3_column_text(stmt, 1);
					const unsigned char* content = sqlite3_column_text(stmt, 2);

					std::cout << "========================================\n";
					std::cout << "ID: " << id << " | ТЕМА: " << title << "\n";
					std::cout << "----------------------------------------\n";
					std::cout << content << "\n"; // Тут выведется весь твой код Ассемблера
					std::cout << "========================================\n\n";
				}
				sqlite3_finalize(stmt); // Очищаем память за запросом
			}

			std::fstream myFile(noteTitle + ".txt", std::ios::in | std::ios::out | std::ios::app);
			

			if (myFile.is_open())
			{

				std::cout << " Откртие : " << noteTitle + ".txt\n";

				std::string insertSQL = "INSERT INTO notes (content) VALUES (?);"; // VALUES (?). ' ? ' - знако вопроса выступает в роли заглушки
				sqlite3_stmt* stmt = nullptr;

				if (sqlite3_prepare_v2(db, insertSQL.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
					
					// Во второй знак вопроса (2) пихаем ДЛИННЫЙ ТЕКСТ С КОДОМ
					sqlite3_bind_text(stmt, 2, noteContent.c_str(), -1, SQLITE_STATIC); // 2 это номер колонки (content)

					if (sqlite3_step(stmt) == SQLITE_DONE) {
						std::cout << " ИТ-заметка успешно сохранена!\n";
					}
					sqlite3_finalize(stmt);

				std::string line;
				while (std::getline(myFile, line )) { // циклом while + std::getline проверяет заполнения.
					std::cout << line +"\n";
				}
				std::cout << "-----------------------\n";
				myFile.clear();

				std::ofstream cont(noteTitle + ".txt\n");
				cont.open(noteTitle + ".txt\n");
				std::cin.ignore();
				std::cout << " Enter Content \n";
				std::getline(std::cin, noteContent);

				myFile << " " + noteContent << "\n";

				std::cout << " New Content is add ! \n";

			}
			else {
				std::cout << " ERROR we didn`t Found File" << noteTitle + ".tht \n";
			}

			sqlite3_close(db);
			std::cout << "4. База данных закрыта. Всё надежно сохранено!" << std::endl;

			return 0;

			// ios — это сокращение от Input/Output Stream (поток ввода-вывода)
		}
		else
		{
			std::cout << "garara here !!!\n";
		}

	} while (userSymb != 1 && userSymb != 2);

	/*else if (userSymb == 2)
{
    // Открываем файл одновременно для чтения (in), записи (out) и дозаписи в конец (app)
    std::fstream myFile(title, std::ios::in | std::ios::out | std::ios::app);

    if (myFile.is_open())
    {
        // 1. ДОПИСЫВАЕМ текст из переменной content в конец файла
        myFile << content << "\n";
        std::cout << "--- Текст успешно дозаписан! ---\n\n";

        // 2. ЧИТАЕМ И СМОТРИМ файл. 
        // Сначала нужно сбросить маркеры ошибки и вернуть указатель чтения в начало файла
        myFile.clear(); 
        myFile.seekg(0, std::ios::beg); 

        std::cout << "--- Текущее содержимое файла: ---\n";
        std::string line;
        while (std::getline(myFile, line))
        {
            std::cout << line << std::endl;
        }
        std::cout << "---------------------------------\n";

    }
    else
    {
        std::cout << "Ошибка: Не удалось открыть существующий файл!\n";
    }
}
*/



	std::cout << "SQLite Version: " << sqlite3_libversion() << std::endl;

	notes_m();

	menu();

	time();

	return 0;
}



/*#include <iostream>

// ... внутри цикла do-while ...

std::cout << " Press ' 1 ' to Create\n Press ' 2 ' to Existing file\n";

std::cin >> *userSymb;

// 1. ПРОВЕРКА: Ввел ли пользователь буквы вместо цифр?
if (std::cin.fail()) 
{
    std::cout << " [ЗАЩИТА] Обнаружен некорректный ввод (буквы/мусор)! Выход...\n";
    
    // Сбрасываем флаг ошибки, чтобы cin снова ожидал команды
    std::cin.clear(); 
    
    // Вытряхиваем ВЕСЬ мусор хакера из буфера. 
    // Поскольку мы сразу выходим, здесь можно очистить буфер до конца строки.
    std::cin.ignore(32767, '\n'); 
    
    // Красиво освобождаем память и выходим из программы/цикла
    delete userSymb;
    userSymb = nullptr;
    break; // Выбрасывает из do-while
}

// 2. ПРОВЕРКА: Число-то ввели, но вдруг это не 1 и не 2? (Например, ввели 999)
if (*userSymb != 1 && *userSymb != 2)
{
    std::cout << " [ЗАЩИТА] Неверный пункт меню! Допускаются только 1 или 2.\n";
    std::cin.ignore(32767, '\n'); // Стираем хвост строки на всякий случай
    continue; // Сразу отправляет на начало цикла, игнорируя ветки создания/открытия файлов
}

// 3. Если всё чётко — убираем ОДИН застрявший Enter, как ты и делал
std::cin.ignore(); 

// Дальше спокойно идут твои: if (*userSymb == 1) ... else if (*userSymb == 2)

*/