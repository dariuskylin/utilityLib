/*
 * =====================================================================================
 *
 *       Filename:  test-sizeof.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/07/2012 12:37:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
using namespace std;
int main()
{
    int m[100];
    int rev = sizeof m;
    cout<<rev<<endl;
    return 0;
}
