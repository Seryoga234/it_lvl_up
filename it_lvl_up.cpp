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

	std::string title;
	std::string content;

	std::cout << " Enter title\n";
	std::getline(std::cin, title);


	do
	{
		std::cout << " Do you wanna Create or Existing file\n";
		std::cout << " Press ' 1 'to Create\n Press ' 2 ' to Existing file\n";
		int* userSymb = new int();

		const short a = 2;

		std::cin >> *userSymb;
		if (*userSymb == 1)
		{
			//delete userSymb;
			//userSymb= nullptr;
			std::ofstream myFile(title + ".txt");
			std::cout << "fasds\n";
		}
		else if (*userSymb == a)
		{
			//delete userSymb;
			//userSymb = nullptr;

			std::fstream myFile(title + ".txt", std::ios::in | std::ios::out | std::ios::app);
			

			if (myFile.is_open())
			{
				std::cout << " Откртие : " << title + ".txt\n";

				std::string line;
				while (std::getline(myFile, line )) {
					std::cout << line +"\n";
				}
				std::cout << "-----------------------\n";
				myFile.clear();

				std::ofstream cont(title + ".txt\n");
				cont.open(title + ".txt\n");
				std::cin.ignore();
				std::cout << " Enter Content \n";
				std::getline(std::cin, content);

				myFile << " " + content << "\n";

				std::cout << " New Content is add ! \n";

			}
			else {
				std::cout << " ERROR we didn`t Found File" << title + ".tht \n";
			}

			// ios — это сокращение от Input/Output Stream (поток ввода-вывода)
		}
		else
		{
			std::cout << "garara here !!!\n";
		}

	} while (true);

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