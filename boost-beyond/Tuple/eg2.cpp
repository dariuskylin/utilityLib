/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 05:48:03 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<boost/tuple/tuple.hpp>

class base {
    public:
        virtual ~base() { } 
        virtual void test() {
            std::cout<< "base::test()" <<std::endl;
        }
};
class derived : public base {
   public:
       virtual void test() {
           std::cout<< "derived::test()" <<std::endl;
       }
};

int main() {
    boost::tuple<int, std::string, derived> tup1(-5, "Tuples");
    boost::tuple<unsigned int, std::string, base> tup2;

    tup2 = tup1;

    tup2.get<2>().test();
    std::cout<< "Interesting value: "
        << tup2.get<0>() <<std::endl;

    const boost::tuple<double, std::string, base> tup3(tup2);
    //tup3.get<0>() = 3.14;
    return 0;
}
