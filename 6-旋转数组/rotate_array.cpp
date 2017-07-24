#include <iostream>
#include <vector>
using namespace std;


int rotate(vector<int>a)
{
	int length = a.size();
	int i = 0;
	int j = length - 1;
	int mid = i;

	while (a[i] > a[j])
	{
		if (j - i == 1)
		{
			return a[j];
			break;
		}
		if (a[mid] > a[i])
			i = mid;
		if (a[mid] < a[j])
			j = mid;
		mid = (i + j) / 2;
	}
	return a[i];
}

int main()
{
	int n;
	vector<int>a;
	while (cin >> n)
	{
		a.clear();
		int tmp;
		for (int i = 0; i < n; ++i)
		{
			cin >> tmp;
			a.push_back(tmp);
		}
		int min = rotate(a);
		cout << min << endl;
	}
	return 0;
}