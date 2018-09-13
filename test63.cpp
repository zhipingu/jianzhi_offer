#include <iostream>
#include <string>
#include <vector>

using namespace std;

int MaxDiff(int a[],int len)
{
    if(!a || len < 2)
        return 0;

    int min=a[0];
    int maxdiff=0;

    for(int i=1;i<len;++i)
    {
        int diff=a[i]-min;
        if(diff > maxdiff)
            maxdiff=diff;

        if(a[i] < min)
            min=a[i];
    }

    return maxdiff;
}

int main()
{
    int a[]={9,11,8,5,7,12,16,14};
    cout << MaxDiff(a,sizeof(a)/sizeof(a[0]))<<endl;
	return 0;
}
