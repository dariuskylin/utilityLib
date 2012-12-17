/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 06:19:55 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/bind.hpp>

//这个程序主要为了解释占位符的概念
//占位符表示提供给最后生成的函数对象的参数，最多支持9个
//第一个参数将替换_1,第二个参数替换_2,以此类推
//在本程序中也就是，i1替换_1,i2替换_2......
void triple_arguments(
        int i1, int i2, int i3) {
    std::cout<< i1 << i2 << i3 <<std::endl;
}

int main() {
    int i1 = 1, i2 = 2, i3 = 3;
    (boost::bind(&triple_arguments,_3,_1,_2))
        (i1, i2, i3);
    return 0;
}
