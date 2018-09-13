#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

#define MaxValue 6

void printProbability(int n)
{
    if (n < 1)
        return;

    int** timesOfSum = new int*[n+1]();
    for(int i = 1; i <= n; ++i)
    {
        timesOfSum[i] = new int[MaxValue * i + 1]();
    }

    for(int i = 1; i <= MaxValue; ++i)
    {
        timesOfSum[1][i] = 1;
    }
    
    for(int i = 2; i <= n; ++i)
    {
        for(int j = i; j <= i * MaxValue; ++j)
        {
            int k = 1;
            while(j - k >= i - 1 && k <= MaxValue) 
            {
                if(j-k<=(i-1)*MaxValue)
                    timesOfSum[i][j] += timesOfSum[i-1][j-k];
                ++k;
            }
            

        }
    }

    int total=pow(MaxValue,n);
    for(int j = n; j <= MaxValue * n; ++j)
    {
        cout <<j<< ":" << " " << (double)timesOfSum[n][j] / total << endl;
    }
}
// 一维数组实现
void printProbability_1(int n)
{
    if (n < 1)
        return;

    int* timesOfSum = new int[n*MaxValue+1]();

    for(int i = 1; i <= MaxValue; ++i)
    {
        timesOfSum[i] = 1;
    }
    
    for(int i = 2; i <= n; ++i)
    {
        for(int j = i; j <= i * MaxValue; ++j)
        {
            int k = 1;
            while(j - k >= i - 1 && k <= MaxValue) 
            {
                if(j-k<=(i-1)*MaxValue)
                    timesOfSum[j] += timesOfSum[j-k];
                ++k;
            }
            

        }
    }

    int total=pow(MaxValue,n);
    for(int j = n; j <= MaxValue * n; ++j)
    {
        cout <<j<< ":" << " " << (double)timesOfSum[j] / total << endl;
    }
}

int main()
{
    printProbability(3);
	return 0;
}
