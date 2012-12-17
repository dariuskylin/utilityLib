/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 10:23:49 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<vector>
#include<boost/function.hpp>
#include<algorithm>

void print_new_value(int i) {
    std::cout <<
        "The value has been updated and is now "
        << i <<std::endl;
}
void interested_in_the_change(int i) {
    std::cout <<
        "Ah, the value has changed." <<std::endl;
}

class notifier {
    private:
        typedef void (*function_type)(int);
    public:
        void add_observer(function_type t) {
            vec_.push_back(t);
        }

        void change_value(int i) {
            value_ = i;
            for( std::size_t i = 0; i < vec_.size(); i++) {
                (*vec_[i])(value_);
            }
        }
    private:
        std::vector<function_type> vec_;
        int value_;
};

int main() {
    notifier n;
    n.add_observer(&print_new_value);
    n.add_observer(&interested_in_the_change);

    n.change_value(42);
    return 0;
}
