/*
 * =====================================================================================
 *
 *       Filename:  writer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/2012 07:55:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"Im.helloworld.pb.h"
#include<fstream>
#include<iostream>

using namespace std;

int main()
{
    Im::helloworld msg1;
    msg1.set_id(111);
    msg1.set_str("hello");

    fstream output("log",ios::out|ios::trunc|ios::binary);
    if(!msg1.SerializeToOstream(&output))
    {
        cerr<<"Failed to write msg."<<endl;
        return -1;
    }
    return 0;
}

