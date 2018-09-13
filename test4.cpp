#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool Find(int *p,int rows,int columns,int key)
{
	int r=0,c=columns-1;
	if(p==nullptr||rows<=0||columns<=0)
	{
		cout<<"input invalid"<<endl;
		return false;
	}
	while(r<rows&&c>=0)
	{
		if(key>p[r*columns+c]) ++r;
		else if(key<p[r*columns+c]) --c;
			 else 
			 {
				 return true;
			 }

	}
	return false;
}

int main()
{
	int a[][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int key;
	cin>>key;
	//cout<<Find(&a[0][0],4,4,key)<<endl;
	cout<<Find(nullptr,4,4,key)<<endl;
	return 0;
}
