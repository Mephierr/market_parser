#include <iostream>
#include <string>
#include <curl/curl.h>
#include <gumbo.h>
#include <sqlite3.h>
#include "nlohmann/json.hpp" 
#include "ConfigManager/ConfigManager.hpp"
#include "HtmlParser/HtmlParser.hpp"
#include "Database/Database.hpp"
#include "ProductAnalyzer/ProductAnalyzer.hpp"
#include "UserInterface/UserInterface.hpp"


int main() {
    ConfigManager config;
    config.loadConfig();

    HtmlParser parser;
    Database db;
    ProductAnalyzer analyzer;
    UserInterface ui;

    db.connect();
    
    std::string url = ui.getUserInput();
    std::string html = parser.fetchPage(url);
    parser.parseHtml(html);

    db.saveProduct("Sample Product");
    analyzer.analyzePricing();
    analyzer.compareProducts();
    ui.showResults();

    return 0;
}