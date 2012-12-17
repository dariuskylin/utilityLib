/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg3.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 04:15:45 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<boost/any.hpp>

int main() {
    std::cout<< "Example of using any member function" <<std::endl;

    boost::any a1(100);
    boost::any a2(std::string("200"));
    boost::any a3;

    std::cout<< "a3 is ";
    if(!a3.empty()) {
        std::cout<< "not ";
    }
    std::cout<< " empty" <<std::endl;

    a1.swap(a2);
    try {
        std::string s = boost::any_cast<std::string>(a1);
        std::cout<< "a1 contains a string: " << s <<std::endl;
    }
    catch(boost::bad_any_cast& e) {
        std::cout<< "I guess a1 doesnt contain a string" <<std::endl;
    }

    if(int* p = boost::any_cast<int>(&a2)) {
        std::cout<< "a2 seems to have swapped contents with a1: "
            << *p <<std::endl;
    }
    else {
        std::cout<< "Nope, no int in a2" <<std::endl;
    }

    if(typeid(int) == a2.type()) {
        std::cout<< "a2's type_info equals the type_info of int" <<std::endl;
    }
    return 0;
}
