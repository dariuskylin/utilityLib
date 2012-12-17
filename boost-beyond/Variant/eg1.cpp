/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 05:17:37 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<boost/variant.hpp>

template <typename V>
void print(V& v) {
    if(int* pi = boost::get<int>(&v)) {
        std::cout<< "It's an int: " << *pi <<std::endl;
    }
    else if(std::string* ps = boost::get<std::string>(&v)) {
        std::cout<< "It's an string: " << *ps <<std::endl;
    }
    else if(double* pd =boost::get<double>(&v)) {
        std::cout<< "It's an double: " << *pd <<std::endl;
    }
    std::cout<< "My work here is done!" <<std::endl;
}

int main() {
    boost::variant<int, std::string, double>
        my_first_variant("Hello there!");
    print(my_first_variant);
    my_first_variant = 12;
    print(my_first_variant);
    my_first_variant = 1.1;
    print(my_first_variant);
    return 0;
}
