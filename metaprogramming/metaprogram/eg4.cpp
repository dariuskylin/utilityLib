/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg4.cpp
 *    Description:  编译期比较大小
 *        Version:  1.0
 *        Created:  11/19/2012 04:56:13 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>

template <int L, int R>
struct static_min {
    static const int value = (L < R) ? L : R;
};

int main() {
    std::cout<< static_min<10, 11>::value <<std::endl;
    return 0;
}
