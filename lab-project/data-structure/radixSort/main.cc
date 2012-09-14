/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/07/2012 08:09:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

void radixSort(vector<int>& ivec, int d){
    int i,j;
    int digit = 1;
    if(ivec.size() == 0){
        cout<<"the sequence length is 0"<<endl;
        return;
    }
    //10个对应于位的队列
    queue<int> digitQueue[10];
    for(i = 0;i<d;++i){
        //将向量中的数依次进入相应位的队列中
        for(j = 0;j<ivec.size();j++)
            digitQueue[(ivec[j]/digit)%10].push(ivec[j]);
        //将队列空间回收，用向量来保存排序后的序列
        j = 0;
        for(int digitVal = 0;digitVal<10;++digitVal)
            while(!digitQueue[digitVal].empty()){
                ivec[j] = digitQueue[digitVal].front();
                digitQueue[digitVal].pop();
                j++;
            }
        //每进行一位基数排序，就将中间结果输出显示
        cout<<"after "<<i<<"th sorting,the sequence : "<<endl;
        for(j = 0;j<ivec.size();++j){
            cout<<ivec[j]<<" ";
        cout<<endl;
        
        //从个位数开始，直到第d位数
        digit *=10;
        }
    }
}
int main(){
    vector<int> seq;
    int input;
    int d;
    //cout<<"please input the sequence to sort(-1 end):"<<endl;
    //cin>>input;
    //while(-1!=input){
        //seq.push_back(input);
    //}
    seq.push_back(92);
    seq.push_back(83);
    seq.push_back(5);
    seq.push_back(420);
    seq.push_back(503);
    seq.push_back(22);
    seq.push_back(39);
    seq.push_back(178);
    seq.push_back(364);
    //cout<<"pleae input the max radix number:"<<endl;
    //cin>>d;
    d=3;
    radixSort(seq,d);
    return 0;
}
