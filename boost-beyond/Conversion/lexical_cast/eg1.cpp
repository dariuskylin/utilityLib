/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 10:13:25 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<boost/lexical_cast.hpp>

int main() {
    //string to int
    std::string s = "42";
    int i = boost::lexical_cast<int>(s);
    std::cout<<i<<std::endl;

    //float to string
    float f = 3.14151;
    s = boost::lexical_cast<std::string>(f);
    std::cout<<s<<std::endl;

    //literal to double
    double d = boost::lexical_cast<double>("2.52");
    std::cout<<d<<std::endl;

    //Failed conversion
    s = "Not an int";
    try {
        i = boost::lexical_cast<int>(s);
    }
    catch(boost::bad_lexical_cast& e) {
        std::cout<< e.what() <<std::endl;
    }
    return 0;
}
