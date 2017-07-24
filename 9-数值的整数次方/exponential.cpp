#include <iostream>

using namespace std;

double expo(double num,int n)
{
	if(n==0)
		 return 1;
	if(n==1)
		 return num;
	 double result =  expo(num,n>>1);
	 result*=result;
	 if(n&0x1==1)
		 result*=num;
	 return result;
}

int main()
{
	int n,num;
	while(cin>>num)
	{
		cin>>n;
		cout<<expo(num,n)<<endl;
	}
	return 0;
}