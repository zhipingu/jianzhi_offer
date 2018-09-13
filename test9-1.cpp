#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

template<typename T>
class Cstack
{
	private:
		queue<T> q1;
		queue<T> q2;
	public:
//		void ctop();
		T cpop();
		void cpush(const T& t);

};

template<typename T>
T Cstack<T>::cpop()
{
	T tail;
	if(q1.empty()&&q2.empty())
		cerr<<"stack is empty"<<endl;
	if(!q1.empty())
	{
		while(q1.size()>1)
		{
			T& tmp=q1.front();
			q2.push(tmp);
			q1.pop();
		}

		tail=q1.front();
		q1.pop();
		return tail;

	}
	if(!q2.empty())
	{
		while(q2.size()>1)
		{
			T& tmp=q2.front();
			q1.push(tmp);
			q2.pop();
		}
		tail=q2.front();
		q2.pop();
		return tail;
	}
	return tail;
}

template<typename T>
void Cstack<T>::cpush(const T& t)
{
	if(q1.empty())q2.push(t);
	else q1.push(t);
}

int main()
{
	Cstack<int> s;
//	for(int i=0;i<10;++i)
//		s.cpush(i);
	for(int i=0;i<10;++i)
		cout<<s.cpop()<<endl;
	return 0;
}
