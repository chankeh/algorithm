#include <iostream>
using namespace std;

int find_first_k(int a[],int low,int high,int k)
{
	int mid = (low+high)/2;
    if(low>high)
		   return -1;
	if(a[mid]==k)
	{
		if(mid>0&&a[mid-1]!=k)
			return mid;
		else 
			high = mid-1;//这个地方要注意不能漏掉
	}
	else if(a[mid]>k)
	{
		high = mid-1;
	}
	else
	{
		low = mid+1;
	}
	return find_first_k(a,low,high,k);
}

int find_last_k(int a[],int low,int high,int k)
{
	 if(low>high)
		   return -1;
	int mid = (low+high)/2;
	if(a[mid]==k)
	{
		if(mid>0&&a[mid+1]!=k)
			return mid;
		else
			low = mid+1;
	}
	else if(a[mid]>k)
	{
		high = mid-1;
	}
	else
	{
		low = mid+1;
	}
	return find_last_k(a,low,high,k);
}


int getTimes(int a[],int k,int n)
{
	int left = find_first_k(a,0,n-1,k);
	int right = find_last_k(a,0,n-1,k);
	int nar = right - left;
	return nar;
}
int main()
{
	int a[] = {1,2,3,3,3,3,4,5};
	cout<<getTimes(a,3,8)<<endl;
	
	return 0;
}