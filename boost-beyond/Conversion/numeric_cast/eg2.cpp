/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 09:56:59 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/limits.hpp>

int main() {
    unsigned char c;
    long l = std::numeric_limits<unsigned char>::max()+14;

    c = l;
    std::cout<< "c is:   " << (int)c <<std::endl;
    long reduced = l%(std::numeric_limits<unsigned char>::max()+1);
    std::cout<< "reduced is: " <<reduced<<std::endl;
    return 0;
}
