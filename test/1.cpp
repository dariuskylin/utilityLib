#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
	int N;
	int splitIndex;
	int H,Min;
	string timeStr;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>timeStr;	
		splitIndex=timeStr.find(":",0);
		H=atoi((timeStr.substr(0,splitIndex)).c_str());
		Min=atoi((timeStr.substr(splitIndex+1)).c_str());
		if(Min!=0)
		{
			cout<<"0"<<endl;
		}
		else
		{
			H=(H+12)%24;
			H=(H==0?24:H);
			cout<<H<<endl;
		}
	}
	return 0;
}
