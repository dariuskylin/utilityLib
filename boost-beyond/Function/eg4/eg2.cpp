/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  带状态的函数对象（2）
 *        Version:  1.0
 *        Created:  11/16/2012 11:38:08 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/function.hpp>

class keeping_state {
    public:
        keeping_state() : total_(0) { }
        
        int operator()(int i) {
            total_ += i;
            return total_;
        }

        int total() const {
            return total_;
        }
    private:
        int total_;
};

int main() {
    keeping_state ks;
    boost::function<int(int)> f1;
    f1 = boost::ref(ks);

    boost::function<int(int)> f2;
    f2 = boost::ref(ks);

    std::cout<< "The current total is " << f1(10) <<std::endl;
    std::cout<< "The current total is " << f2(10) <<std::endl;
    std::cout<< "After adding 10 two times, the total is "
        << ks.total() <<std::endl;
    return 0;
}
