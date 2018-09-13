#include<iostream>
#include<string>
#include<vector>

using namespace std;

void replace_blank(char c[],int capacity)
{
	if(c==nullptr||capacity<=0)
	{
		perror("c is invalid");
		return;
	}
	int i=0;
	int oldlen=0,blanknum=0;
	while(c[i]!='\0')
	{
		++oldlen;
		if(c[i]==' ')
		++blanknum;
		++i;
	}
	int newlen=oldlen+2*blanknum;
	if(newlen>capacity)
	{
		cout<<"over capacity"<<endl;
		return;
	}
	cout<<"newlen:"<<newlen<<endl;
	int oldindex=oldlen,newindex=newlen;
	for(;oldindex>=0&&newindex>oldindex;)
	{
		if(c[oldindex]!=' ')
		c[newindex--]=c[oldindex--];
		else
		{
			c[newindex--]='0';
			c[newindex--]='2';
			c[newindex--]='%';
			--oldindex;
		}
	}
}

int main()
{

	char c[6]="abc ";
	replace_blank(c,6);
	cout<<c<<endl;
	char *p=c;
	cout<<p<<endl;
	cout<<c[6]<<endl;
	return 0;
}
