#include <iostream>
#include <vector>

using namespace std;


//传统做法
bool  isUgly(int number)
{
	if(number%2==0)
		 return isUgly(number/2);
	else if(number%3==0)
		 return isUgly(number/3);
	 else if(number%5==0)
		  return isUgly(number/3);
	 else
	    return number==1?true:false;
}

//使用空间换取时间
int getNumber(int n)
{
	if(n<=1)
		 return 0;
	 int a=0,b=0,c=0;
	 int i = 1;
	 int *arr = new int[n];
	 arr[0] = 1;
	 while(i<n)
	 {
		 arr[i] = min(arr[a]*2,min(arr[b]*3,arr[c]*5));
		 if(arr[i]==arr[a]*2)
			    ++a;
	     if(arr[i]==arr[b]*3)
			  ++b;
		 if(arr[i]==arr[c]*5)
			   ++c;
		 ++i;
	 }
	 return arr[i-1];
}



int findUgly(int n)
{
	 if(n<=0)
        return 0;
     int number = 0;
     int uglyfound = 0;
	 while(uglyfound<n)
	 {
		 ++number;
		 if(isUgly(number))
			 ++uglyfound;
	 }
	 return number;
}

int main()
{
	int n;
	while(cin>>n)
	{
		//cout<<findUgly(n)<<endl;
	    cout<<getNumber(n)<<endl;
	}
	return 0;
}