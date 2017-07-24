#include <iostream>
#include <string>
using namespace std;

int convert(string str)
{
	int n = str.length();
     if((n<1||n==1&&str[0]=='-')||((n<1||n==1&&str[0]=='+')))
		 return 0;
	 int i=0,sum = 0;
     int flag = 1;	
	  if(str[0]=='-')
		 {
			 flag = -1;
			 ++i;
		 }
	   else if(str[0]=='+')
	   {
		   flag = 1;
		   ++i;
	   }
 	while(i<n)
	 {
		 if(!(str[i]>='0'&&str[i]<='9'))
			  return 0;
		 sum+=(str[i]-'0');
		 if(i<n-1)
			 sum*=10;
		 else if(i==n-1)
		 {
			 sum*=flag;	
			 break;
		 }		 
		 ++i;
	 }
	return sum;
}
int main()
{
	string str;
	while(cin>>str)
	{
		cout<<convert(str)<<endl;
	}
	return 0;
}