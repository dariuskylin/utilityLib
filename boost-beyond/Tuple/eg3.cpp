/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg3.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 05:59:29 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<boost/tuple/tuple.hpp>
#include<boost/tuple/tuple_comparison.hpp>

int main() {
    boost::tuple<int, std::string> tup1(11,"Match?");
    boost::tuple<short, std::string> tup2(12,"Match?");

    std::cout<< std::boolalpha;
    std::cout<< "Comparison: tup1 is less than tup2" <<std::endl;

    std::cout << "tup1 == tup2: " << (tup1 == tup2) <<std::endl;
    std::cout << "tup1 != tup2: " << (tup1 != tup2) <<std::endl;
    std::cout << "tup1 < tup2: " << (tup1 < tup2) <<std::endl;
    std::cout << "tup1 > tup2: " << (tup1 > tup2) <<std::endl;
    std::cout << "tup1 <= tup2: " << (tup1 <= tup2) <<std::endl;
    std::cout << "tup1 >= tup2: " << (tup1 >= tup2) <<std::endl;

    tup2.get<0>() = boost::get<0>(tup1);
    std::cout << "tup1 == tup2: " << (tup1 == tup2) <<std::endl;
    std::cout << "tup1 != tup2: " << (tup1 != tup2) <<std::endl;
    std::cout << "tup1 < tup2: " << (tup1 < tup2) <<std::endl;
    std::cout << "tup1 > tup2: " << (tup1 > tup2) <<std::endl;
    std::cout << "tup1 <= tup2: " << (tup1 <= tup2) <<std::endl;
    std::cout << "tup1 >= tup2: " << (tup1 >= tup2) <<std::endl;
    return 0;
}
