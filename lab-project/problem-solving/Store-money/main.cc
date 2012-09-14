/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/31/2012 12:48:08 AM
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

int main(){
    double month[49];
    double rate = 0.0171;
    month[48] = 1000;
    for(int i = 47;i>0;i--){
        month[i] = (month[i+1]+ month[48])/(1+rate/12);
    }
    for(int i=48;i>0;i--){
        cout<<"第"<<i<<"个月末本利合计："<<month[i]<<endl;
    }
    return 0;
}
