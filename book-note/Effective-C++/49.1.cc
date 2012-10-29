/*
 * =====================================================================================
 *
 *       Filename:  49.1.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/16/2012 11:48:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
#include<cstdlib>
#include<new>

void outOfMem(){
    std::cerr<<"Unable to satisfy request for memory\n";
    std::abort();
}

int main(){
    std::set_new_handler(outOfMem);
    int* pBigDataArray = new int[1000000000000L];

    return 0;
}
