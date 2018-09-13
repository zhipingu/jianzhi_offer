#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int lastRemain(int n,int m)
{
    if(n < 1 || m < 1)
        return -1;

    list<int> ring;
    for(int i = 0; i < n; ++i)
    {
        ring.push_back(i);
    }

    auto cur=ring.begin();
    vector<int> ivec;
    while(ring.size() > 1)
    {

        for(int i = 1;i < m;++i)
        {
            ++cur;
            if(cur == ring.end())
                cur=ring.begin();
        }
        ivec.push_back(*cur);
        cur=ring.erase(cur);
        if(cur==ring.end())
            cur=ring.begin();
    }

    for(auto r:ivec)
        cout<<r<<endl;
    cout<<"=========="<<endl;
    return *cur;

}

int main()
{

    cout << lastRemain(5,3) << endl;
	return 0;
}
