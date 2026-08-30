#include <iostream>
#include "notes_memory.h"
#include "sqlite3.h"
#include <string>
#include <fstream>

/*void ДобавитьЗаметку(sqlite3* db, std::string текст) {
    std::string sql = "INSERT INTO notes (text) VALUES (?);";
    sqlite3_stmt* stmt = nullptr;
    
    // Вся эта системная дрочь пишется один раз внутри функции:
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, текст.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }
}*/



int notes_m() {

    setlocale(LC_ALL, "Russian");

    sqlite3* db = nullptr;  // sqlite3 - база данных

    std::string noteTitle;
    std::string noteContent;

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


    std::string insertSQL = "INSERT INTO notes (title, content) VALUES (?,?);"; // VALUES (?). ' ? ' - знако вопроса выступает в роли заглушки
    sqlite3_stmt* stmt = nullptr; // sqlite3_stmt - это как контейнер (структура) 
    // внутри sqlite3_stmt - sqlite3_prepare_v2(Сборка коробки) , sqlite3_bind_text(Загрузка в к...) , sqlite3_step(Запуск к...) , sqlite3_finalize

    if (sqlite3_prepare_v2(db, insertSQL.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        // В первый знак вопроса (1) пихаем НАЗВАНИЕ
        sqlite3_bind_text(stmt, 1, noteTitle.c_str(), -1, SQLITE_STATIC); //для сохранения. 1 это номер колонки (title)

        // Во второй знак вопроса (2) пихаем ДЛИННЫЙ ТЕКСТ С КОДОМ
        sqlite3_bind_text(stmt, 2, noteContent.c_str(), -1, SQLITE_STATIC); // 2 это номер колонки (content)

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            std::cout << " ИТ-заметка успешно сохранена!\n";
        }
        sqlite3_finalize(stmt); // Убрали мусор из оперативки
    }


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
        sqlite3_finalize(stmt);
    }





    // 5. ШАГ ТРЕТИЙ: Читаем все заметки из файла (SELECT)
    //std::string selectSQL = "SELECT id, text FROM notes;";

    if (sqlite3_prepare_v2(db, selectSQL.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        std::cout << "\n--- СПИСОК ЗАМЕТОК ИЗ ФАЙЛА ---" << std::endl;

        // Цикл идет по строкам базы, пока они там есть
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // Вытаскиваем ID из нулевой колонки (id)
            int id = sqlite3_column_int(stmt, 0); // на нулевой позиции в первом ящике/колонке.
            // Вытаскиваем ТЕКСТ из первой колонки (text)
            std::string text = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));//
            // 1 - это во втором ящике. UTF-8 - динамический 1 байт(подстривается).
            // reinterpret_cast - дает права const char* на внутренний unsigned char* 

            // Выводим на экран то, что прочитали из файла
            std::cout << "Заметка #" << id << ": " << text << std::endl;
        }
        std::cout << "--------------------------------\n" << std::endl;

        sqlite3_finalize(stmt); // Очищаем память за запросом
    }


    // 6. Закрываем базу данных, сохраняя все изменения на диск
    sqlite3_close(db);
    std::cout << "4. База данных закрыта. Всё надежно сохранено!" << std::endl;

    return 0;

}