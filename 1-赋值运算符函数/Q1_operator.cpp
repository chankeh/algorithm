#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class MyString{
public:
	MyString();//默认构造
	MyString(const char *str);//有参数构造
	MyString(const MyString &str);//拷贝构造
	MyString& operator=(const MyString &str);//赋值函数
	~MyString();//析构函数
private:
	char *m_data;
};

//赋值函数
MyString& MyString::operator=(const MyString &str)
{
	if (this == &str)
		return *this;
	delete m_data;
	m_data = NULL;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
	m_data[strlen(str.m_data)] = '\0';
	cout << "operator assign" << endl;
	return *this;
}

//拷贝构造函数
MyString::MyString(const MyString &tmp)
{
	int len = strlen(tmp.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, tmp.m_data);
}
//有参构造函数
MyString::MyString(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];
		m_data[0] = '\0';
	}
	else
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
}
//默认构造函数
MyString::MyString()
{
	cout << "default constructor" << endl;
}
//析构函数
MyString::~MyString()
{
	cout << "decostructor execute." << endl;
	delete m_data;
}

int main()
{
	MyString s1("aasdsjkfjd");
	MyString s2;
	s2 = s1;
	system("pause");
	return 0;
}

