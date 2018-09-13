#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int maxValueOfGift(int value[],int rows,int cols)
{
	if(!value || rows<=0 || cols<=0)
		return 0;
	int **max=new int*[rows];
	for(int i=0;i<rows;++i)
		max[i]=new int[cols]();

	max[0][0]=value[0];
	for(int i=0;i<rows;++i)
		for(int j=0;j<cols;++j)
		{
			int up=0,left=0;
			if(i>0)
				up=max[i-1][j];
			if(j>0)
				left=max[i][j-1];

			max[i][j]=std::max(up,left)+value[i*cols+j];
		}

	int maxValue=max[rows-1][cols-1];
	delete[] max;
	
	return maxValue;
}

int main()
{
	
	//int value[]={1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5};

	int value[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	cout<<maxValueOfGift(value,4,4)<<endl;
	return 0;
}
