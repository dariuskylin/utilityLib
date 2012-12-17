/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/17/2012 01:44:49 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/signals.hpp>

void my_first_slot() {
    std::cout << "void my_first_slot()" << std::endl;
}

class my_second_slot {
    public:
        void operator()() const {
            std::cout  <<
                "void my_second_slot::operator()() const"
                <<std::endl;
        }
};

int main() {
    boost::signal<void()> sig_;

    sig_.connect(&my_first_slot);
    sig_.connect(my_second_slot());

    std::cout << "Emitting a signal..." <<std::endl;

    sig_();
    return 0;
}
