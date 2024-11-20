#include<iostream>


class Database {
    
public:
    void connect() ;

    void saveProduct(const std::string &product) ;

    void getProduct() ;
};