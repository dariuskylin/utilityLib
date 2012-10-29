/*
 * =====================================================================================
 *
 *       Filename:  test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2012 01:45:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"pre_1.1.h"
#include<iostream>

int main(){
    int array[ 10 ] = { 0, 1,2,3,4,5,6,7,8,9 };
    Point< int, 10 > pt(array);
    std::cout<<"point[4]="<<pt[4]<<std::endl;
    std::cout<<pt<<std::endl;

    return 0;
}
