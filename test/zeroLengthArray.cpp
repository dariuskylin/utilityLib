/*
 * =====================================================================================
 *
 *       Filename:  zeroLengthArray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/22/2011 01:56:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (dyc), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
#include<cstdlib>
using namespace std;

struct device
{
    int num;
    int count;
    int reserve[0];
};
int main()
{
    struct device *p_dev=(struct device*)malloc(sizeof(struct device)+sizeof(int)*25);
    p_dev->reserve[0]=99;
    p_dev->reserve[24]=0;
    cout<<"p_dev->reserve[0]="<<p_dev->reserve[0]<<endl;
    cout<<"p_dev->reserve[24]="<<p_dev->reserve[24]<<endl;
    cout<<"sizeof(struct device)="<<sizeof(struct device)<<endl;

    int a=*(&(p_dev->count)+1);
    cout<<"a="<<a<<endl;
    return 0;
}
