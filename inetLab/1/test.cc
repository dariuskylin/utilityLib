/*
 * =====================================================================================
 *
 *       Filename:  test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2012 10:23:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"InetAddr.h"
#include<iostream>
using namespace std;
int main()
{
    InetAddress addr1("192.168.1.116",2222);
    InetAddress addr2("192.168.1.137",1234);
    InetAddress addr3("192.168.1.116",2222);
    cout<<"address of addr1:"<<addr1.toIpPort()<<endl;
    cout<<"address of addr2:"<<addr2.toIpPort()<<endl;
    cout<<"address of addr3:"<<addr3.toIpPort()<<endl;
    cout<<"ipNetEndian of addr1:"<<addr1.ipNetEndian()<<endl;
    cout<<"portNetEndian of addr1:"<<addr1.portNetEndian()<<endl;
    if(addr1 == addr2)
        cout<<"addr1 == addr2"<<endl;
    else
        cout<<"addr1 != addr2"<<endl;
    if(addr1 == addr3)
        cout<<"addr1 == addr3"<<endl;
    else
        cout<<"addr != addr3"<<endl;
    return 0;
}
