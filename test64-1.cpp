#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef int (*fun)(int);

int getSum(int n)
{
    return 0;
}

int getSumN(int n)
{
    fun pfun[]={getSum,getSumN};
    return n+pfun[!!(n-1)](n-1);
}
int main()
{
    int n;
    cin>>n;
    cout << getSumN(n) <<endl;
	return 0;
}
