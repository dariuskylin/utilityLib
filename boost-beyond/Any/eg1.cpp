/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/15/2012 09:08:21 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<boost/any.hpp>

class A {
    public:
        void some_function() {
            std::cout<< "A::some_function()" <<std::endl;
        }
};

class B {
    public:
        void some_function() {
            std::cout<< "B::some_function()" <<std::endl;
        }
};

class C {
    public:
        void some_function() {
            std::cout<< "C::some_function()" <<std::endl;
        }
};

int main() {
    std::cout<< "Example of using any." <<std::endl;
    std::vector<boost::any> store_anything;

    store_anything.push_back(A());
    store_anything.push_back(B());
    store_anything.push_back(C());

    store_anything.push_back(std::string("This is fantastic! "));
    store_anything.push_back(3);
    store_anything.push_back(std::make_pair(true,7.92));

    void print_any(boost::any& a);

    std::for_each(
            store_anything.begin(),
            store_anything.end(),
            print_any);
    return 0;
}

void print_any(boost::any& a) {
    if(A* pA = boost::any_cast<A>(&a)) {
        pA->some_function();
    }
    else if(B* pB = boost::any_cast<B>(&a)) {
        pB->some_function();
    }
    else if(C* pC = boost::any_cast<C>(&a)) {
        pC->some_function();
    }
    else {
        try {
            std::cout<< boost::any_cast<std::string>(a) <<std::endl;
        }
        catch(boost::bad_any_cast& e) {
            std::cout<< "Oops!" <<std::endl;
        }
    }
}
