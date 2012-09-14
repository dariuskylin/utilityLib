/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2012 04:13:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

const int SIZE = 10;

void QuickSort(int *arr,int left,int right){
    int f,t;
    int rtemp,ltemp;

    ltemp = left;
    rtemp = right;
    f = arr[(ltemp+rtemp)/2];
    while(ltemp<rtemp){
        while(arr[ltemp]<f){
            ltemp++;
        }
        while(arr[rtemp]>f){
            rtemp--;
        }
        if(ltemp<=rtemp){
            t = arr[ltemp];
            arr[ltemp] = arr[rtemp];
            arr[rtemp] = t;
            --rtemp;
            ++ltemp;
        }
    }
    if(ltemp == rtemp)
    {
        ltemp++;
    }
    if(left < rtemp){
        QuickSort(arr,left,ltemp-1);
    }
    if(right > ltemp){
        QuickSort(arr,rtemp+1,right);
    }
}

int main(){
    int i;
    int arr[SIZE];
    srand(time(NULL));
    for(i=0;i<SIZE;i++)
    {
        arr[i] = rand()%1000+100;
    }
    cout<<"Before Quick Sort:"<<endl;
    for(i=0;i<SIZE;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    QuickSort(arr,0,SIZE-1);
    cout<<"After Quick Sort:"<<endl;
    for(i=0;i<SIZE;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
