/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg3.cpp
 *    Description:  元函数转发
 *        Version:  1.0
 *        Created:  11/19/2012 04:39:45 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */

#include<iostream>

template <typename T1, typename T2>
struct select1st{
    typedef T1 type;
};

/* 
template <typename T1, typename T2>
struct forward {
    typedef typename select1st<T2, T1>::type type;
};
*/
template <typename T1, typename T2>
struct forward : select1st<T2, T1> {};

int main() {
    forward<int, double>::type m = 9.4;
    std::cout<< m <<std::endl;
    return 0;
}
