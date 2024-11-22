#pragma once
#ifndef HTMLPARSER_HPP
#define HTMLPARSER_HPP

#include<iostream>

class HtmlParser {
public:
    HtmlParser(const std::string& url);
    bool fetch();
    void parse();
    void printLinks();
private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
    void extractLinks(GumboNode* node);
    
};

#endif /*HTMLPARSER_HPP*/