#pragma once
#ifndef HTMLPARSER_HPP
#define HTMLPARSER_HPP

#include<iostream>

class HtmlParser {
public:
    std::string fetchPage(const std::string &url) ;

    void parseHtml(const std::string &html) ;
    
};

#endif /*HTMLPARSER_HPP*/