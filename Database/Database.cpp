#include<iostream>
#include "Database.hpp"
#include <sqlite3.h>

class Database {
private:
    sqlite3 *db;

public:
    void connect() {
        // Подключаемся к SQLite базе данных
        int rc = sqlite3_open("products.db", &db);
        if(rc) {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        } else {
            std::cout << "Opened database successfully." << std::endl;
        }
    }

    void saveProduct(const std::string &product) {
        // Сохраняем продукт в базе данных
        std::cout << "Saving product: " << product << std::endl;
    }

    void getProduct() {
        // Получаем продукт из базы данных
        std::cout << "Getting product..." << std::endl;
    }
};