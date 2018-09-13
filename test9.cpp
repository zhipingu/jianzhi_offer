#include<iostream>
#include<stack>
#include<stdexcept>
using namespace std;

template<typename T>
class CQueue
{
	public:
		CQueue()=default;
		~CQueue()=default;
		void appendTail(const T& node);
		T deleteHead();
	private:
		stack<T>stack1;
		stack<T>stack2;
};
template<typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			T& tmp=stack1.top();
			stack1.pop();
			stack2.push(tmp);
		}
	}
	try
	{
		if(stack2.empty()) 
			throw new runtime_error("queue is empty");
	}
	catch(runtime_error *r)
	{
		cout<<r->what()<<endl;
		exit(1);
	}
	T tmp=stack2.top();
	stack2.pop();
	
	return tmp;

}

int main()
{
	CQueue<int> q;
	for(int i=0;i<10;++i)
	{
		q.appendTail(i);
	}
	for(int i=0;i<10;++i)
		cout<<q.deleteHead()<<endl;
	q.appendTail(11);
	q.appendTail(12);
	cout<<q.deleteHead()<<endl;
	cout<<q.deleteHead()<<endl;
	cout<<q.deleteHead()<<endl;
	return 0;

}
