#include <iostream>

using namespace std;

long long fib(int n)
{
	int fb[] = {0,1};
	if(n<2)
		 return fb[n];
	 long long  one = 0,two = 1;
	 long long save = 0;
	 for(int i=2;i<=n;++i)
	 {
		 save = two;
		 two = one+two;
		 one = save;
	 }
	 return two;
}


int main()
{
	long n;
	while(cin>>n)
	{
		cout<<fib(n)<<endl;
	}
	return 0;
}