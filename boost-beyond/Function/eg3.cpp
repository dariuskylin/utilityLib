/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg3.cpp
 *    Description:  Function和类成员函数
 *        Version:  1.0
 *        Created:  11/16/2012 11:04:36 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/function.hpp>

class some_class {
    public:
        void do_stuff(int i) const {
            std::cout<< "OK. Stuff is done. " <<std::endl;
        }
};
int main() {
    boost::function<void(some_class, int)> f1;
    f1 = &some_class::do_stuff;
    f1(some_class(), 2);

    boost::function<void(some_class&, int)> f2;
    f2 = &some_class::do_stuff;
    some_class s1;
    f2(s1, 1);

    boost::function<void(some_class*, int)> f3;
    f3 = &some_class::do_stuff;
    some_class s2;
    f3(&s2, 3);
    return 0;
}
