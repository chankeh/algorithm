#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;


template<typename T>
class StackWithMin{
public:
    void Push(T& val);
	void Pop();
	T min();
private:
    stack<T> s_data;
	stack<T> s_min;
};

template<typename T>
void StackWithMin<T>::Push(T& val)
{
	s_data.push(val);
	if(s_min.size()==0||s_min.top()>val)
		  s_min.push(val);
	else
		  s_min.push(s_min.top());
}
template<typename T>
void StackWithMin<T>::Pop()
{
	assert(s_data.size()>0&&s_min.size()>0);
	s_data.pop();
	s_min.pop();
}
template<typename T>
T StackWithMin<T>::min()
{
	assert(s_data.size()>0&&s_min.size()>0);
	return s_min.top();
}


int main()
{
	StackWithMin<int> sw;
	int val,n;
      cin>>n;
		while(n--)
		{
			cin>>val;
			sw.Push(val);
		}
		cout<<sw.min()<<endl;
	return 0;
}
