#include <iostream>

using namespace std;

int count_bin(int n)
{
	int count = 0;
	while(n)
	{
		n = n&(n-1);
		count++;
	}
	return count;
}

int main()
{
	int n;
	while(cin>>n)
	{
		cout<<count_bin(n)<<endl;
	}
	return 0;
}