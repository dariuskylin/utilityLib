/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/19/2012 04:31:55 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>

template <typename T1, typename T2>
struct select1st{
    typedef T1 type;
};
int main() {
    select1st<int, int>::type m = 4;
    std::cout<< m <<std::endl;
    return 0;
}
