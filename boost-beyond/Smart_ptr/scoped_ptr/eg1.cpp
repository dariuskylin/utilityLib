/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/13/2012 05:41:14 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<boost/scoped_ptr.hpp>
#include<iostream>

struct Shoe { ~Shoe() { std::cout<<"Buckle my shoe\n"; } };

class MyClass {
    public:
        MyClass() : ptr(new int) {
            *ptr = 0;
        }
        int add_one() {
            return ++*ptr;
        }
    private:
        boost::scoped_ptr<int> ptr;
};

int main() {
    boost::scoped_ptr<Shoe> x(new Shoe);
    MyClass my_instance;
    std::cout << my_instance.add_one() << std::endl;
    x.reset(new Shoe);
    std::cout << my_instance.add_one() << std::endl;
    return 0;
}
