/*
 * =====================================================================================
 *
 *       Filename:  test-objectCounter.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/07/2012 07:29:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
#include"objectCounter.hpp"
using std::cout;
using std::endl;
using namespace NDSL::simple;
struct node
{
     int index;
     ObjectCounter<node> node_cnter;
};
int main()
{
    node a;
    cout<<ObjectCounter<node>::getObjCnt()<<endl;
    cout<<ObjectCounter<node>().getObjCnt()<<endl;
    cout<<ObjectCounter<node>::getObjCnt()<<endl;
    return 0;
}
