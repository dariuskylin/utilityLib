/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  test.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/09/2012 07:58:15 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<string>
#include<iostream>

#include"md5.h"

using std::string;

int main() {
    string c,key;
    std::cout<<"Please input phrase:"<<std::endl;
    std::cin>>c;
    if( c == "c" )
        return 0;
    CMD5 iMd5;
    iMd5.GenerateMD5((unsigned char*)c.c_str(),c.size());
    key = iMd5.ToString();
    std::cout<<key<<std::endl;
    return 0;
}
