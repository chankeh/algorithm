#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int>&arr, int begin, int end)
{
	if(begin==end)
		   return begin;
	int pivot = arr[end];
	while (begin<end)
	{
		while (begin<end&&arr[begin] < pivot)
			begin++;
		if(begin<end)
			 arr[end] = arr[begin];
		while (begin<end&&arr[end] >= pivot)
			end--;
		if (begin<end)
			 arr[begin] = arr[end];
	}
	arr[end] = pivot;
	return end;
}
void findMinK(vector<int>arr, int begin, int end, int k)
{	
    vector<int>out;
	int idx = partition(arr, begin, end);
	while (idx != k - 1)
	{
		if (idx>k - 1)
		{
			end = idx - 1;
			partition(arr, begin, end);
		}
		else if (idx<k - 1)
		{
			begin = idx + 1;
			partition(arr, begin, end);
		}
	}
	 for(int i=0;i<k;++i)
			cout<<arr[i]<<" ";
		 
		cout << endl;
}


int main()
{
	int n, k;
	while (cin >> n)
	{
		vector<int>arr;
 
		for (int i = 0; i<n; ++i)
		{
			int s;
			cin >> s;
			arr.push_back(s);
		}
		int k;
		cin >> k;
		 findMinK(arr, 0, arr.size() - 1, k);
       
	}
	return 0;
}