#pragma once
#ifndef DATABASE_HPP
#define DATABASE_HPP

#include<iostream>
class Database {
    
public:
    void connect() ;

    void saveProduct(const std::string &product) ;

    void getProduct() ;
};

#endif /*DATABASE_HPP*/