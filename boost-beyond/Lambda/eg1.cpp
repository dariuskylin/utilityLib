/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 10:17:31 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/lambda/lambda.hpp>
#include<boost/function.hpp>

int main() {
    using namespace boost::lambda;
    (std::cout << _1 << " " << _3 << " " << _2 << "!\n")
        ("Hello","friend","my");

    boost::function<void(int, int, int)> f =
        std::cout << _1 << "*" << _2 << "+" << _3
        << "=" <<_1*_2+_3 << "\n";;
    f(1, 2, 3);
    f(3, 2, 1);
    return 0;
}
