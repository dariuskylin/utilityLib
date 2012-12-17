/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 01:51:24 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/cast.hpp>
#include<string>

class base1 {
    public:
        virtual void print() {
            std::cout<< "base1::print()" <<std::endl;
        }

        virtual ~base1() { }
};

class base2 {
    public:
        void only_base2() {
            std::cout<< "only_base2()" <<std::endl;
        }
        
        virtual ~base2() { }
};

class derived : public base1, public base2 {
    public:
        void print() {
            std::cout<< "derived::print()" <<std::endl;
        }

        void only_here() {
            std::cout<< "derived::only_here()" <<std::endl;
        }

        void only_base2() {
            std::cout<< "Oops, here too!" <<std::endl;
        }
};

int main() {
    base1* p1 = new derived;
    p1->print();
    try {
        derived* pD = boost::polymorphic_cast<derived*>(p1);
        pD->print();
        pD->only_base2();
        pD->only_here();

        base2* pB = boost::polymorphic_cast<base2*>(p1);
        pB->only_base2();
    }
    catch(std::bad_cast& e) {
        std::cout<< e.what() <<std::endl;
    }
    delete p1;
    return 0;
}
