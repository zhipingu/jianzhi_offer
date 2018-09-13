#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;
#define MaxValue 6

void Probability(int n,int start,int sum,int *timesOfSum)
{
    if(start == n + 1)
    {
        ++timesOfSum[sum];
        return;
    }

    for(int i = 1; i <= MaxValue; ++i)
    {
        Probability(n,start + 1,sum + i,timesOfSum);
    }
}

void PrintProbability(int n)
{
  if(n < 1)
      return;

  int *timesOfSum = new int[6*n+1]();
  int sum=0;
  for(int i = 1; i <= MaxValue; ++i)
  {
      Probability(n,2,sum+i,timesOfSum);
  }
  int total = pow(6,n);

  for(int i = n;i <= 6 * n;++i)
  {
      cout<<i<<":"<<(double)timesOfSum[i] / total<<endl;
  }
}
int main()
{

    PrintProbability(3);
	return 0;
}
