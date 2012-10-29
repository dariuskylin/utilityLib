/*
 * =====================================================================================
 *
 *       Filename:  sizeof-null-class.cc
 *
 *    Description:  
 *
 *        Created:  10/22/2012 01:11:52 AM
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *           Copyright [2012]   <dongyuchi>
 *
 * =====================================================================================
 */
#include<iostream>

class X {};
class Y : public virtual X {};
class Z : public virtual X {};
class A : public Y, public Z {};
class B : public X {};

int main() {
    std::cout<<"sizeof(X):"<<sizeof(X)<<std::endl;
    std::cout<<"sizeof(Y):"<<sizeof(Y)<<std::endl;
    std::cout<<"sizeof(Z):"<<sizeof(Z)<<std::endl;
    std::cout<<"sizeof(A):"<<sizeof(A)<<std::endl;
    std::cout<<"sizeof(B):"<<sizeof(B)<<std::endl;
    return 0;
}
