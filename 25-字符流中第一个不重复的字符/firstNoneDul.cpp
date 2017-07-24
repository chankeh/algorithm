#include <iostream>
#include <string.h>
using namespace std;

char find_char(char str[],int n)
{
	int i = 0;
	int count[256] = {0};
	while(i<n)
	{
		count[str[i]]++;
		++i;
	}
	for(i=0;i<n;++i)
	{
		if(count[str[i]]==1)
			break;
	}
	return str[i];
}

int main()
{
	char str[256];
	memset(str,'\0',256);
	while(cin>>str)
	{
		cout<<find_char(str,strlen(str))<<endl;
	}
	return 0;
}