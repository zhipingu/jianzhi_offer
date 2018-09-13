#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

bool isContinuous(int a[],int len)
{
    if(!a || len <= 0)
        return false;
    sort(a,a+len);
    int numOfZero=0;
    int numOfGap=0;

    for(int i=0; i<len && a[i]==0; ++i)
    {
        ++numOfZero;
    }

    for(int start=numOfZero,end=start+1; end < len; ++end)
    {
        if(a[start] == a[end])
            return false;
        numOfGap += a[end]-a[start]-1;
        start=end;
    }

    if(numOfGap <= numOfZero)
        return true;
    return false;
    
}
int main()
{
    int a[]={1,2,3,0,5};
    cout<<isContinuous(a,sizeof(a)/sizeof(a[0]))<<endl;
	return 0;
}
