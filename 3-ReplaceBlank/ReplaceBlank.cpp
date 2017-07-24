#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


void repalce(char str[], int length)
{
	int len = 0, blank = 0;
	if (length == 0)
		return;
	int i = 0;
	while (str[i] != '\0')
	{
		++len;
		if (str[i] == ' ')
			blank++;
		++i;
	}
	int fin_length = len + blank * 2;
	/*if (fin_length > length)
		return;*/
	while (len >= 0)
	{
		if (str[len] == ' ')
		{
			str[fin_length--] = '0';
			str[fin_length--] = '2';
			str[fin_length--] = '%';
		}
		else
		{
			str[fin_length--] = str[len];
		}
		len--;
	}
}

int main()
{
	string s1;

	while (getline(cin, s1))
	{
		int length = s1.length();
		char *str = new char[length * 2];
		//str = c_str(s1);
		strcpy(str, s1.c_str());
		repalce(str, length);
		cout << str << endl;
	}
	return 0;
}