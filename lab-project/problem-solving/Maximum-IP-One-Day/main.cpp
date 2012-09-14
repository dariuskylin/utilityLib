#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

const unsigned N=400000000;      //随机产生的IP地址数
const unsigned FILE_NUM=16;      //产生的小文件个数
const unsigned HASH_SHIFT=28;    //散列值的位移量

inline unsigned HashInt(unsigned value); //将整数散列到0到FILE_NUM之间
bool ProduceIP(string fileName);                //随机产生IP地址，看成是32位无符号数
bool DecomposeFile(string fileName);     //分而治之，将大文件分为若干个小文件
bool FindTargetIP(unsigned result[2]);      //找到出现次数最多的IP

int main()
{
	unsigned start,end;      //记录总的运行时间
	unsigned start1,end1;  //产生大文件的时间
	unsigned start2,end2;  //分解大文件的时间
	unsigned start3,end3;  //找出现IP次数最多的时间

	string name="IP.bin";       //大文件
	unsigned result[2]={0,0};   //保存结果

	start=clock();
	start1=clock();
	//随机产生大量IP
	if(ProduceIP(name)==false)
		return 1;
	end1=clock();

	start2=clock();
	//分而治之
	if(DecomposeFile(name)==false)
		return 1;
	end2=clock();

	start3=clock();
	//找到出现次数最多的IP
	if(FindTargetIP(result)==false)
		return 1;
	end3=clock();
	end=clock();

	//打印结果
	cout<<"total run time : "<<(end-start)/CLOCKS_PER_SEC<<endl;
	cout<<"ProduceIP() run time : "<<(end1-start1)/CLOCKS_PER_SEC<<endl;
	cout<<"DecomposeFile() run time : "<<(end2-start2)/CLOCKS_PER_SEC<<endl;
	cout<<"FindTargetIP() run time : "<<(end3-start3)/CLOCKS_PER_SEC<<endl;
	cout<<"IP : "<<(result[0]>>24)<<'.'<<((result[0]&0x00ff0000)>>16)<<'.';
	cout<<((result[0]&0x0000ff00)>>8)<<'.'<<((result[0]&0x000000ff))<<endl;
	cout<<"appear time : "<<result[1]<<endl;
	return 0;
}
//将整数散列到0到FILE_NUM之间
inline unsigned HashInt(unsigned value)
{
	//斐波那契(Fibonacci)散列法 hash_key=(value * M) >> S;
	//value是16位整数，M = 40503 
	//value是32位整数，M = 2654435769 
	//value是64位整数，M = 11400714819323198485
	//S与桶的个数有数，如果桶的个数为16，那么S为28
	//对于32位整数，S=32-log2(桶的个数)
	return (value*2654435769)>>HASH_SHIFT; 
}
//随机产生IP地址 看成是32位无符号数
bool ProduceIP(string fileName)
{
	ofstream outFile(fileName.c_str(),ios::binary);
	if(!outFile)
	{
		cerr<<"error: unable to open output file : "<<fileName<<endl;
		return false;
	}
	srand(time(0));
	for(unsigned i=0;i<N;i++)
	{
		//产生一个大整数用来模拟IP地址
		unsigned x=((rand()%256)<<24)|((rand()%256)<<16)|((rand()%256)<<8)|(rand()%256);
		outFile.write((char*)&x,sizeof(unsigned));
	}
	return true;
}
//分而治之 将大文件分为若干个小文件
bool DecomposeFile(string fileName)
{
	ofstream outFiles[FILE_NUM];
	int i;
	for(i=0;i<FILE_NUM;i++)
	{
		//小文件的名称
		char buffer[10];
		string name="tmp";
		itoa(i,buffer,10);
		name=name+buffer+".bin";
		//打开小文件
		outFiles[i].open(name.c_str(),ios::binary);
		if(!outFiles[i])
		{
			cerr<<"error: unable to open output file :"<<name<<endl;
			return false;
		}
	}
	ifstream inFile(fileName.c_str(),ios::binary);
	while(inFile.good()) 
	{
		//散列到各个小文件中
		unsigned int value=0;
		if(inFile.read((char*)&value,sizeof(unsigned)))
		{
			outFiles[HashInt(value)].write((char*)&value,sizeof(unsigned));
		}
	}
	//关闭文件
	inFile.close();
	for(i=0;i<FILE_NUM;i++)
		outFiles[i].close();
	return true;
}
//找到出现次数最多的IP
bool FindTargetIP(unsigned result[2])
{
	result[0]=0;
	result[1]=0;
	for(int i=0;i<FILE_NUM;i++)
	{
		char buffer[10];
		string name="tmp";
		itoa(i,buffer,10);
		name=name+buffer+".bin";
		//处理每个小文件
		ifstream inFile;
		inFile.open(name.c_str(),ios::binary);
		if(!inFile)
		{
			cerr<<"error: unable to open input file :"<<name<<endl;
			return false;
		}
		//核心代码，由于STL中没有hash_map，用map来代替
		map<unsigned,unsigned> ip_count;
		while(inFile.good())
		{
			unsigned key=0;
			if(inFile.read((char*)&key,sizeof(unsigned)))
			{
				ip_count[key]++;
			}
		}
		map<unsigned,unsigned>::iterator it=ip_count.begin();
		for(;it!=ip_count.end();it++)
		{
			if(it->second>result[1])
			{
				result[0]=it->first;
				result[1]=it->second;
			}
		}
		inFile.close();
	}
	return true;
}
