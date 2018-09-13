#include<iostream>
#include<string>
#include<vector>

using namespace std;

 vector<vector<int> > FindContinuousSequence(int sum) {
        int small=1,big=2;
        int CurSum=small+big;
        vector<vector<int> > result;
        
        while(small<=sum/2)
        {
            if(CurSum==sum)
            {
                vector<int> tmp;
                for(int i=small;i<=big;++i)
                    tmp.push_back(i);
                result.push_back(tmp);

				++big;
				CurSum+=big;
            }
            else if(CurSum>sum)
            {
                CurSum-=small;
                ++small;
            }
            else
            {
                ++big;
                CurSum+=big;
            }
        }
        return result;
}

int main()
{
	vector<vector<int>> result;
	result=FindContinuousSequence(10);
	for(auto r:result)
	{
		for(auto s:r)
			cout<<s<<" ";
	    cout<<endl;
	}
	cout<<endl;
	return 0;
}
