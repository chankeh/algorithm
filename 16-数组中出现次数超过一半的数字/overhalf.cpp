#include<iostream>
#include <vector>
using namespace std;


int partition(vector<int>arr, int begin, int high)
{
	int pivot = arr[begin];
	
	while (begin<end)
	{
		while (begin<end&&arr[begin]<=pivot)
			begin++;
		while (begin<end&&arr[end]>=pivot)
			end--;
		if (begin<end)
			swap(arr[begin], arr[end]);
	}
	swap(pivot, arr[begin]);
	return begin;
}

int findOverHalf(vector<int>arr)
{
	int begin = 0, end = arr.size();
	int mid = arr.size() >> 1;
	int idx = partition(arr, begin, end);
	while (idx != mid)
	{
		if (idx>mid)
		{
			end = idx - 1;
			idx = partition(arr, begin, end);
		}
		else if (idx<mid)
		{
			begin = idx + 1;
			idx = partition(arr, begin, end);
		}
	}
	return arr[idx];
}

int main()
{

	int n;
	while (cin >> n)
	{
		vector<int>arr;
		int tmp;
		for (int i = 0; i<n; ++i){
			cin >> tmp;
			arr.push_back(tmp);
		}
		cout << findOverHalf(arr) << endl;
	}
	return 0;
}