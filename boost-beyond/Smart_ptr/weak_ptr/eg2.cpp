/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 12:25:36 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<boost/shared_ptr.hpp>
#include<boost/weak_ptr.hpp>
#include<iostream>
#include<string>

int main() {
    boost::shared_ptr<std::string>
        sp(new std::string("Some resource"));
    boost::weak_ptr<std::string> wp(sp);
    std::cout<<"sp-use_count:"<<sp.use_count()<<std::endl;
    std::cout<<"wp-use_count:"<<wp.use_count()<<std::endl;
    if(boost::shared_ptr<std::string> p = wp.lock()){
        std::cout<<"Got it:"<<*p<<std::endl;
    }
    else {
        std::cout<<"Nah, the shared_ptr is empty"<<std::endl;
    }
    std::cout<<"sp-use_count:"<<sp.use_count()<<std::endl;
    std::cout<<"wp-use_count:"<<wp.use_count()<<std::endl;
    std::cout<<"After:"<<*sp<<std::endl;
    return 0;
}
