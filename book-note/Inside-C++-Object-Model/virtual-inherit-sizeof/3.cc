/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  3.cc
 *    Description:  
 *        Version:  1.0
 *        Created:  10/30/2012 10:16:43 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>

class A { };
class B { 
    int b;
};
class C { };
class D { };
class E : public virtual A, public virtual B,
    public virtual C, public virtual D
{ };
int main() {
    std::cout<<sizeof(E)<<std::endl;
    return 0;
}
