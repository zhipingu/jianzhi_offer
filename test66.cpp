#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int>& A) {
        size_t len=A.size();
        vector<int> B(len,0);
        B[0]=1;
        // 从上到下，计算下三角
        for(int i=1;i<len;++i)
        {
            B[i]=B[i-1]*A[i-1];
        }
        
        vector<int> tmp(len,0);
        // 从下到上，计算上三角
        tmp[len-1]=1;
        // B[len-1]=tmp[len-1]*B[len-1];
        for(int i=len-2;i>=0;--i)
        {
            tmp[i]=tmp[i+1]*A[i+1];
            B[i] *= tmp[i];
        }
        
        return B;
 }
 
 int main()
 {
    vector<int> A={1,2,3,4,5,6,7,8,9};
    vector<int> B=multiply(A);
    for(auto r:B)
      cout<<r<<" ";
    cout<<endl;
 }
