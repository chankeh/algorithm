#include <iostream>

using namespace std;

void printChar(char *str)
{
 
	int i=0;
	while(str[i]=='0')
		++i;
	cout<<str+i<<endl;		
    
	//cout<<str<<endl;
}

void printNum(char* str,int n,int index)
{
    if(n==index)
	{
		printChar(str);
		return ;
	}		
	for(int i=0;i<10;++i)
	{
		str[index] = i+'0';
		printNum(str,n,index+1);
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		char *str = new char[n+1];
		memset(str,'0',n);
		str[n] = '\0';
		printNum(str,n,0);
	}
	return 0;
}