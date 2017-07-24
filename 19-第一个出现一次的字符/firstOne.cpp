#include <iostream>

using namespace std;

char count_first(char str[])
{
	int i=0;
	int count[256] = {0};
	while(str[i]!='\0')
	{
		count[str[i]]++;
		++i;
	}
	for(i=0;i<256;++i)
	{
		if(count[i]==1)
			break;
	}
	return i;
}

int main()
{
	char str[1024];
	memset(str,'\0',1024);
	while(cin>>str)
	{
		cout<<count_first(str)<<endl;
	}
	return 0;
}