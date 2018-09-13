#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class stack_min
{
public:
	stack_min()=default;
	void pop();
	void push(int key);
	int top();
	int min();

private:
	stack<int> s;
	stack<int> mins;

};

void stack_min::pop()
{
	if(mins.empty() || s.empty())	
	{
		cerr<<"stack_min is empty"<<endl;
		return;
	}

	mins.pop();
	s.pop();
}

int stack_min::top()
{

	if(mins.empty() || s.empty())	
	{
		cerr<<"stack_min is empty"<<endl;
		exit(1);
	}

	return s.top();

}

void stack_min::push(int key)
{
	if(mins.size()==0 || key<mins.top()) 
		mins.push(key);
	else 
		mins.push(mins.top());

	s.push(key);

}

int  stack_min::min()
{
	if(mins.empty() || s.empty())
	{
		cerr<<"stack_min is empty"<<endl;
		exit(1);
	}

	return mins.top();
}

int main()
{
	stack_min s;
	int a[]={4,7,5,3,12,1,6};
	int len=sizeof(a)/sizeof(a[0]);

	for(int i=0;i<len;++i)
	{
		s.push(a[i]);
		cout<<a[i]<<" ";
	}
	cout<<endl;

	for(int i=0;i<len;++i)
	{
		cout<<"min:"<<s.min()<<" ";
		s.pop();
	}
	cout<<endl;
	return 0;
}
