#include<iostream>
using namespace std;


int Add(int num1, int num2)
{
	int sum;
	int carry=1;
	while(carry!=0)
	{
		sum=num1 ^ num2;

		carry=(num1 & num2) << 1;

		num1=sum;
		num2=carry;
	}
	return sum;
}

int main()
{
	cout<<Add(4,6)<<endl;
	return 0;
}
