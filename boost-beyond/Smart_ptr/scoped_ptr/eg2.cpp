/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/13/2012 06:27:31 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<boost/scoped_ptr.hpp>
#include<iostream>
#include<string>

int main() {
    boost::scoped_ptr<std::string>
        p(new std::string("Use scoped_ptr often."));

    //print the value of the string
    if(p)
        std::cout<<*p<<std::endl;
    //get the size of the string
    size_t i = p->size();
    //assign a new value to the string
    *p = "Acts just like a pointer.";
    return 0;
}
