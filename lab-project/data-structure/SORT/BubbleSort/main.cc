/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2012 02:00:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

const int SIZE = 10;

void BubbleSort(int *a,int len){
    int i,j,k,temp;
    for(i = 0;i<len-1;i++){
        for(j = i+1;j<=len-1;j++){
            if(a[j]<a[i]){
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
        cout<<"After "<<i+1<<" th step sort:"<<endl;
        for(k = 0;k<len;k++){
            cout<<a[k]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int array[SIZE];
    int i;
    srand(time(NULL));
    for(i=0;i<SIZE;i++){
        array[i] = rand()%1000+100;
    }
    cout<<"Before sort:"<<endl;
    for(i=0;i<SIZE;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    BubbleSort(array,SIZE);

    cout<<"After sort:"<<endl;
    for(i = 0;i<SIZE;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
