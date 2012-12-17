/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 09:02:00 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<boost/regex.hpp>
#include<iostream>

int main() {
    boost::regex reg("(A.*)");
    bool b = boost::regex_match(
            "This expression could match from A and beyond.",
            reg);
    std::cout<<b<<std::endl;

    b = boost::regex_match(
            "As this string starts with A, does it match?",
            reg);
    std::cout<<b<<std::endl;
    return 0;
}
