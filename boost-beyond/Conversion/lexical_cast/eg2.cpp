/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 10:23:49 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/lexical_cast.hpp>

template<typename T>
std::string to_string(const T& arg) {
    try {
        return boost::lexical_cast<std::string>(arg);
    }
    catch(boost::bad_lexical_cast& e) {
        return "";
    }
}

int main() {
    std::string s = to_string(412);
    std::cout<<s<<std::endl;
    s  = to_string(2.357);
    std::cout<<s<<std::endl;
    return 0;
}
