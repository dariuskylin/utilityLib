/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 09:36:36 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/cast.hpp>
#include<boost/limits.hpp>

int main() {
    std::cout<< "large_to_smaller example" <<std::endl;
    
    long l = std::numeric_limits<short>::max();
    short s = l;
    std::cout<< "s is: " << s <<std::endl;
    s=++l;
    std::cout<< "s is: " << s <<std::endl;

    try {
        l = std::numeric_limits<short>::max();
        s = boost::numeric_cast<short>(l);
        std::cout<< "s is: " << s <<std::endl;
        s = boost::numeric_cast<short>(++l);
        std::cout<< "s is: " << s <<std::endl;
    }
    catch(boost::bad_numeric_cast& e) {
        std::cout<< e.what() <<std::endl;
    }
    return 0;
}
