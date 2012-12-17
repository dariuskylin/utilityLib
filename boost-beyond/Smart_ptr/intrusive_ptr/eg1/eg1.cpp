/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/13/2012 11:06:50 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include"reference_counter.hpp"
#include<boost/intrusive_ptr.hpp>
#include<iostream>

class some_class : public reference_counter {
    public:
        some_class() {
            std::cout<< "some_class::some_class()" <<std::endl;
        }
        some_class(const some_class& other) {
            std::cout<< "some_class(const some_class&)" <<std::endl;
        }
        ~some_class() {
            std::cout<< "some_class::~some_class()" <<std::endl;
        }
};
int main() {
    std::cout << "Before start of scope" <<std::endl;
    {
        boost::intrusive_ptr<some_class> p1(new some_class(),true);
        boost::intrusive_ptr<some_class> p2(p1,true);
    }
    std::cout<< "After end of scope" <<std::endl;
    return 0;
}
