#include<iostream>
#include<string>
#include<vector>
#include<string>

using namespace std;

int jump_stairs(int n)
{
	int N=0,NMinusOne=2,NMinusTwo=1;
	int result[3]={0,1,2};
	if(n<0)
	{
		cout<<"n is invalid"<<endl;
		exit(1);
	}
	else if(n<3)
		{
			return result[n];
		}
	for(int i=3;i<=n;++i)
	{
		N=NMinusOne+NMinusTwo;
		NMinusTwo=NMinusOne;
		NMinusOne=N;
	}
	return N;
}

int main(int argc,char **argv)
{
	cout<<"argc:"<<argc<<endl;
	cout<<argv[0]<<endl;
	cout<<jump_stairs(stoi(argv[1]))<<endl;
	return 0;
}
