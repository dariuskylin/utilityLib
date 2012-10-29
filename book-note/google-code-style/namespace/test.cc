/*
 * =====================================================================================
 *
 *       Filename:  test.cc
 *
 *    Description:  
 *
 *        Created:  10/22/2012 12:58:58 AM
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *           Copyright [2012]   <dongyuchi>
 *
 * =====================================================================================
 */
#include"func.h"
#include<iostream>

int main() {
    nimei::zhen::func f;
    namespace he = ::nimei::zhen;
    he::func h;
    std::cout<<h.fun()<<std::endl;
    std::cout<<f.fun()<<std::endl;
    return 0;
}
