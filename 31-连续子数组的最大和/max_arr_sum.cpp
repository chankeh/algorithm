#include <iostream>
#include <algorithm>
using namespace std;

int find_max(int *a,int n)
{
    int curr = 0;
    int total = a[0];
    for(int i=1;i<n;++i)
     {
         if(curr<0)
             curr = a[i];
         else
             curr+=a[i];
         total = max(curr,total);
     }
    return total;
}


int main()
{
   int a[]={1,-2,3,10,-4,7,2,-5};
   cout<<find_max(a,8)<<endl;
   return 0;
}
