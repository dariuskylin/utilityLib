/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg3.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 09:30:17 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<boost/bind.hpp>

class some_class {
    public:
        typedef void result_type;
        void print_string(const std::string& s) const {
            std::cout<< s <<std::endl;
        }
};

void print_string(const std::string& s) {
    std::cout<< s <<std::endl;
}

int main() {
    //绑定自由函数（非成员函数）
    (boost::bind(&print_string,_1))("Hello func!");
    //绑定成员函数
    //method 1
    some_class sc;
    (boost::bind(&some_class::print_string,_1,_2))(sc,"Hello member");
    //method 2
    (boost::bind(&some_class::print_string,some_class(),_1))("Hello member");
    //method 3
    (boost::bind(&some_class::print_string,some_class(),"Hello member"))();
    return 0;
}
