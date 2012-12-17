/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 05:42:50 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<string>

#include<boost/tuple/tuple.hpp>

int main() {
    boost::tuple<int, double, std::string>
        triple(42, 3.14, "The amazing tuple!");

    int i = boost::tuples::get<0>(triple);
    std::cout<< i <<std::endl;
    double d = triple.get<1>();
    std::cout<< d <<std::endl;
    std::string s = triple.get<2>();
    std::cout<< s <<std::endl; 
    return 0;
}
