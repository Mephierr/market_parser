#include"UserInterface.hpp"
#include<iostream>

class UserInterface {
public:
    void showResults() {
        // Показываем результаты анализа
        std::cout << "Showing results..." << std::endl;
    }

    std::string getUserInput() {
        std::string input;
        std::cout << "Enter a URL: ";
        std::cin >> input;
        return input;
    }
};