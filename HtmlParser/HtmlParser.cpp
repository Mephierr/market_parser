#include<iostream>
#include <curl/curl.h>
#include <gumbo.h>
#include"HtmlParser.hpp"

class HtmlParser {
public:
    std::string fetchPage(const std::string &url) {
        // Используем libcurl для получения страницы
        CURL *curl;
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        std::string readBuffer;

        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, nullptr);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
        return readBuffer;
    }

    void parseHtml(const std::string &html) {
        // Используем Gumbo для парсинга
        GumboOutput* output = gumbo_parse(html.c_str());
        gumbo_destroy_output(&kGumboDefaultOptions, output);
        std::cout << "HTML parsed." << std::endl;
    }
};