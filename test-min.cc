/*
 * =====================================================================================
 *
 *       Filename:  test-min.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/06/2012 11:51:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<algorithm>
#include<iostream>
using std::cout;
using std::endl;
using std::min;
using std::cin;
int main()
{
    int m,n;
    cin>>m>>n;
    m=min(m,n);
    cout<<m<<endl;
    return 0;
}
