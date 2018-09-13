#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

class A
{
    public:
        A()
        {
            ++n;
            sum += n;
        }
        static int getSum()
        {
            return sum;
        }
    private:
        static int n;
        static int sum;
};

int A::n=0;
int A::sum=0;

int main()
{
    // int i=-1;
    // printf("%d\n",i&128);
    int n;
    cin>>n;
    A *p=new A[n];
    delete[] p;
    cout << A::getSum()<<endl;
	return 0;
}
