#include<iostream>
#include"ConfigManager.hpp"

class ConfigManager {
public:
    void loadConfig() {
        // Загружаем конфигурацию
        std::cout << "Loading configuration..." << std::endl;
    }
    
    void saveConfig() {
        // Сохраняем конфигурацию
        std::cout << "Saving configuration..." << std::endl;
    }
};