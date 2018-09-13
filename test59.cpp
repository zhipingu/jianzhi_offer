// maxInWindow.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> max;
	deque<int> window;

	// 条件很重要，num.size()<size
	if (num.size() < size || size <= 0)
		return max;

	for (int i = 0; i < size; ++i)
	{
		if (!window.empty() && num[i] > num[window.back()])
			window.pop_back();
		window.push_back(i);
	}

	for (int i = size; i<num.size(); ++i)
	{
		max.push_back(num[window.front()]);

		while (!window.empty() && num[i] > num[window.back()])
			window.pop_back();
		window.push_back(i);

		while (!window.empty() && window.front() <= i - size)
		{
			window.pop_front();
		}
	}
	max.push_back(num[window.front()]);
	return max;
}

int main()
{
	vector<int> num = { 2,3,4,2,6,2,5,1 };
	vector<int> max = maxInWindows(num, 3);
	for (auto r : max)
		cout << r << " ";
	cout << endl;
    return 0;
}


