/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description: dynamic_cast和polymorphic_cast的对比 
 *        Version:  1.0
 *        Created:  11/14/2012 02:03:35 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/cast.hpp>

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

void polymorphic_cast_example(base1* p) {
    derived* pD = boost::polymorphic_cast<derived*>(p);
    pD->print();
    pD->only_here();
    pD->only_base2();

    base2* pB = boost::polymorphic_cast<base2*>(p);
    pB->only_base2();
}

void dynamic_cast_example(base1* p) {
   derived* pD = dynamic_cast<derived*>(p); 
   if(!pD) {
       throw std::bad_cast();
   }
   pD->print();
   pD->only_here();
   pD->only_base2();

   base2* pB = dynamic_cast<base2*>(p);
   if(!pB) {
       throw std::bad_cast();
   }
   pB->only_base2();
}

int main() {
    base1* p = new derived;
    try {
        polymorphic_cast_example(p);
        dynamic_cast_example(p);
    }
    catch(std::bad_cast& e) {
        std::cout<< e.what() <<std::endl;
    }
    delete p;
    return 0;
}
