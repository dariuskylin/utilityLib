/*
 * =====================================================================================
 *
 *       Filename:  pre.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2012 12:19:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>

int main(){
    bool isTrue = true;

    if(isTrue){
        std::cerr<<"true"<<std::endl;
    }else{
        std::cerr<<"false"<<std::endl;
    }

    return 0;
}
