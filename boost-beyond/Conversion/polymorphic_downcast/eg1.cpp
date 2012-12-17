/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 02:53:23 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/cast.hpp>

struct base {
    virtual ~base() {}
};

struct derived1 : public base {
    void foo() {
        std::cout<< "derived1::foo()" <<std::endl;
    }
};

struct derived2 : public base {
    void foo() {
        std::cout<< "derived2::foo()" <<std::endl;
    }
};

void older(base* p) {
    derived1* pd = static_cast<derived1*>(p);
    pd->foo();
}

void newer(base* p) {
    derived1* pd = boost::polymorphic_downcast<derived1*>(p);
    pd->foo();
}

int main() {
    derived2* p = new derived2;
    older(p);
    newer(p);
    return 0;
}
