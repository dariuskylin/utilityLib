/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/19/2012 03:37:13 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<boost/config.hpp>
#include<iostream>

template <int N, int M>
struct meta_func1 {
    BOOST_STATIC_CONSTANT(int, value = N+M);
};

int main() {
    std::cout<< meta_func1<10, 10>::value <<std::endl;
    return 0;
}
