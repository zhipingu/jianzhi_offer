#include<iostream>
#include<string>
#include<deque>
#include<queue>

using namespace std;
class  custom_queue
{
private:
queue<int> que;
deque<int> minque;
deque<int> maxque;
public:
void push(int val)
{
	que.push(val);
	while ((!minque.empty()) && (minque.back() > val))
		minque.pop_back();
	minque.push_back(val);
	while ((!maxque.empty()) && (maxque.back() < val))
		maxque.pop_back();
	maxque.push_back(val);
}
void pop()
{
	int value = que.front();
	que.pop();
	if (minque.front() == value)
		minque.pop_front();
	if (maxque.front() == value)
		maxque.pop_front();
}
int findmin()
{
	return minque.front();
}
int findmax()
{
	return maxque.front();
}
};
int main()
{
	custom_queue cq;
	int a[]={15,2,8,5,13,12,6,2,15,12,6,8,12};
	for(int i=0;i<sizeof(a)/sizeof(a[0]);++i)
	{
		cout<<a[i]<<" ";
		cq.push(a[i]);
	}
	cout<<endl;

	for(int i=0;i<sizeof(a)/sizeof(a[0]);++i)
	{
		cout<<"max:"<<cq.findmax()<<" ";
		cout<<"min:"<<cq.findmin()<<" ";
		cq.pop();
		cout<<endl;
	}
	cout<<endl;
	return 0;
}

