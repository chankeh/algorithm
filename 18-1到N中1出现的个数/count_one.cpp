#include <iostream>

using namespace std;


int count_one(int n)
{
	if(n<1)
		return 0;
	int base = 1;
	int round = n;
	int count = 0;
	while(round>0)
	{
		int weight = round%10;
		round/=10;
		count+=round*base;
		if(weight==1)
			count+=(n%base)+1;
		else if(weight>1)
			count+=base;
		base*=10;
	}
	return count;
}

int main()
{
	int n;
	while(cin>>n)
	{
		cout<<count_one(n)<<endl;
	}
	return 0;
}