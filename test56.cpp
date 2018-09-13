#include<iostream>
#include<string>
#include<vector>

using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int resultXOR=0;
        for(auto beg=data.begin();beg!=data.end();++beg)
            resultXOR^=*beg;
       
		//find the first bit is 1
        int indexBit1=0;
        while((resultXOR&1)==0 && indexBit1<8*sizeof(int))
        {
            resultXOR=resultXOR>>1;
            ++indexBit1;
        }
        
        int tmp=1<<indexBit1;
        *num1=*num2=0;
        for(auto beg=data.begin();beg!=data.end();++beg)
        {
            if((*beg&tmp)==0)
                *num1^=*beg;
            else
                *num2^=*beg;
        }
    }
int main()
{
	vector<int> ivec={2,4,3,6,3,2,5,5};
	int num1=0,num2=0;
	FindNumsAppearOnce(ivec,&num1,&num2);
	cout<<num1<<" "<<num2<<endl;
	return 0;
}
