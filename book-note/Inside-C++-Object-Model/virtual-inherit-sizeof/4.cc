/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  4.cc
 *    Description:  
 *        Version:  1.0
 *        Created:  10/30/2012 10:21:55 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>

class A {
    int a;
};
class B {
    int b;
};
class C { };
class E : public virtual A, public virtual B,
    public virtual C
{ };
int main() {
    std::cout<<sizeof(E)<<std::endl;
    return 0;
}
