/*
 * =====================================================================================
 *
 *       Filename:  reader.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/2012 08:03:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"Im.helloworld.pb.h"
#include<iostream>
#include<fstream>

using namespace std;

void ListMsg(const Im::helloworld &msg)
{
    cout<<msg.str()<<endl;
    cout<<msg.id()<<endl;
}

int main()
{
    Im::helloworld msg1;
    fstream input("log",ios::in|ios::binary);
    if(!msg1.ParseFromIstream(&input))
    {
        cerr<<"Failed to parse address book."<<endl;
        return -1;
    }
    ListMsg(msg1);
    return 0;
}
