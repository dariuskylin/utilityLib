/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2012 11:30:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<time.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

const int SIZE=10;

void HeapSort(int *a,int n){
    int i,j,h,k;
    int t;
    //begin heap build
    for(i=n/2-1;i>=0;i--){
        j=2*i+1;
        if(j+1<n){ //make sure j refer to the larger node
            if(a[j]<a[j+1]){
                j++;
            }
        }
        if(a[i]<a[j]){
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    // end  head build
    cout<<"the heap made up of raw data:"<<endl;
    for(h=0;h<n;h++){
        cout<<a[h]<<" ";
    }
    cout<<endl;

    for(i=n-1;i>0;i--){
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        k = 0;
        while(2*k+1<i){
            j = 2*k+1;
            if(j+1<i){
                if(a[j]<a[j+1]){
                    j++;
                }
            }
            if(a[k]<a[j]){
                t = a[k];
                a[k] = a[j];
                a[j] = t;
                k = j;
            }
            else
            {
                break;
            }
        }
        cout<<"After "<<n-i<<" step sort:"<<endl;
        for(h=0;h<n;h++){
            cout<<a[h]<<" ";
        }
    cout<<endl;
    }
}

int main(){
    int arr[SIZE];
    srand(time(NULL));
    for(int i=0;i<SIZE;i++){
        arr[i]=rand()%1000+100;
    }
    cout<<"Before Heap Sort:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    HeapSort(arr,SIZE);

    cout<<"After Heap Sort:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
