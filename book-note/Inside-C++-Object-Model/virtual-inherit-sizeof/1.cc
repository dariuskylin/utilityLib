/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  1.cc
 *    Description:  
 *        Version:  1.0
 *        Created:  10/30/2012 10:09:50 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>

class A {
    virtual void a() { }
};
class A1 {
    virtual void a() { }
};
class B : public A, virtual public A1{
    
};
int main() {
    std::cout<<sizeof(B)<<std::endl;
    return 0;
}
