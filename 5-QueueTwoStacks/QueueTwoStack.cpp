#include <iostream>
#include <stack>
using namespace std;


template<typename T>
class Queue{
public:
	Queue();
	~Queue();
	void InQueue(const T& elem);
	T OutQueue();
	bool isEmpty();
private:
	stack<T> s1, s2;
};

template<typename T>
bool Queue<T>::isEmpty()
{
	if (s2.empty() && s1.empty())
		return true;
	else
		return false;
}
template<typename T>
Queue<T>::Queue()
{
	cout << "construct Queue" << endl;
}
template<typename T>
Queue<T>::~Queue(){
	cout << "deconstructor" << endl;
}
template<typename T>
void Queue<T>::InQueue(const T& elem)
{
	s1.push(elem);
}
template<typename T>
T Queue<T>::OutQueue()
{
	if (s2.size() <= 0)
	{
		while (s1.size() > 0)
		{
			T tmp = s1.top();
			s2.push(tmp);
			s1.pop();
		}
	}
	if (s2.size() == 0)
	{
		throw exception("error");
	}
	T head = s2.top();
	s2.pop();
	return head;
}
int main()
{
	Queue<int>q;
	while (1)
	{

		int tmp;
		cin >> tmp;
		if (tmp == -1)
			break;
		q.InQueue(tmp);

	}
	while (!q.isEmpty())
	{
		int s = q.OutQueue();
		cout << s << " ";
	}
	cout << endl;
	return 0;
}