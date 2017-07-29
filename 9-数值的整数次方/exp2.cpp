#include <iostream>

using namespace std;

int expo_sum(int num,int idx,int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return num;
    if(idx<n)   
        num = num*expo_sum(num,idx+1,n);
     return num;
}


int main()
{
  int num,n;
  while(cin>>num>>n)
    {
       cout<<expo_sum(num,1,n)<<endl;
    }
  return 0;
}
