#include <iostream>

using namespace std;

int only(int a[],int n)
{
	int tmp = a[0];
	int i = 1;
	while(i<n)
	{
		tmp^=a[i];
		++i;
	}
	return tmp;
}


int main()
{
	int a[] = {1,1,2,2,3,3,4,};
	cout<<only(a,7)<<endl;
	 
	return 0;
}