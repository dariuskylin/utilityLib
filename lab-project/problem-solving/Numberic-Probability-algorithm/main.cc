/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/31/2012 02:01:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
double randTick(int n){
    int count = 0;
    for(int i = 0;i<n;i++){
        srand(time(NULL));
        double x =rand()%100/100.0;
        srand(time(NULL));
        double y =rand()%100/100.0;
        if(y<= 1-x*x)
           count++; 
    }
    return (double)count/n;
}
int main(){
    for(int i=1;i<5;i++)
    {
        cout<<"��Ӱ����Ͷ�����Ϊ��"<<randTick(10000)<<endl;
    }
    return 0;
}
