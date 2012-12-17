/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg3.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 12:33:13 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<boost/shared_ptr.hpp>
#include<boost/weak_ptr.hpp>

void access_the_resource(boost::weak_ptr<std::string> wp) {
    boost::shared_ptr<std::string> sp(wp);
    std::cout<< *sp <<std::endl;
}

int main() {
    boost::shared_ptr<std::string>
        sp(new std::string("Some Resource"));
    boost::weak_ptr<std::string> wp(sp);

    access_the_resource(wp);
    return 0;
}
