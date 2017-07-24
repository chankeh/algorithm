#include <iostream>

using namespace std;


void permutation(char* str,char *start)
{
	if(*start=='\0')
		 cout<<str<<endl;
	else
	{
		for(char* pchar = start;*pchar!='\0';++pchar)
		{
			char temp = *start;
			*start = *pchar;
            *pchar = temp;
            permutation(str,start+1);	
            temp = *start;
			*start = *pchar;
            *pchar = temp;			
		}
		
	}
}


int main()
{
	char* str;
	while(cin>>str)
	{
		permutation(str,str);
		
	}
	return 0;
}