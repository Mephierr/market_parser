#include<iostream>
#include <curl/curl.h>
#include <gumbo.h>
#include <string>
#include"HtmlParser.hpp"
#include <vector>

class HtmlParser {
public:
    HtmlParser(const std::string& url) : url(url) {}

    bool fetch() {
        CURL* curl;
        CURLcode res;
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &htmlContent);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            return res == CURLE_OK;
        }
        return false;
    }

    void parse() {
        GumboOutput* output = gumbo_parse(htmlContent.c_str());
        extractLinks(output->root);
        gumbo_destroy_output(&kGumboDefaultOptions, output);
    }
 
    void printLinks() const {
        for (const auto& link : links) {
            std::cout << link << std::endl;
        }
    }

private:
    std::string url;
    std::string htmlContent;
    std::vector<std::string> links;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    void extractLinks(GumboNode* node) {
        if (node->type == GUMBO_NODE_ELEMENT && node->v.element.tag == GUMBO_TAG_A) {
            GumboAttribute* href = gumbo_get_attribute(&node->v.element.attributes, "href");
            if (href) {
                links.push_back(href->value);
            }
        }
        for (size_t i = 0; i < node->v.element.children.length; ++i) {
            extractLinks(static_cast<GumboNode*>(node->v.element.children.data[i]));
        }
    }
};