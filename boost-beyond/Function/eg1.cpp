/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 10:06:40 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/function.hpp>

bool some_func(int i, double d) {
    return i > d;
}

int main() {
    boost::function<bool (int, double)> f;
    //boost::function<bool (int, double)> f(some_func);
    //boost::function<bool (int, double)> f(&some_func);
    f = some_func;
    f = &some_func;
    std::cout<< f(10,1.1) <<std::endl;;
    return 0;
}
