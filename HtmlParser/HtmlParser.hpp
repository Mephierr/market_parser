#include<iostream>
class HtmlParser {
public:
    std::string fetchPage(const std::string &url) ;

    void parseHtml(const std::string &html) ;
    
};