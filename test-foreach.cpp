/*
 * =====================================================================================
 *
 *       Filename:  foreach.cpp
 *
 *    Description:  foreach in c++
 *
 *        Version:  1.0
 *        Created:  05/18/2012 02:56:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include"foreach.h"

using namespace std;

int main()
{
    set<string> s;
    s.insert("w");
    s.insert("a");
    s.insert("n");

    foreach(s,it,set<string>)
    {
        cout<<*it<<endl;
    }
    map<unsigned,string> m;
    m[0] = "x";
    m[1] = "w";
    foreach2(m,it)
    {
        cout<<it->first<<","<<it->second<<endl;
    }
    return 0;
}
