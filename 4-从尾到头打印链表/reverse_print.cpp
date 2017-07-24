#include <iostream>

using namespace std;

class List{
public:
	int data;
	List* next;
};

void create(List* L)
{
	List* p = new List;
	int tmp;
	cin >> tmp;
	while (0 != tmp){
		p->data = tmp;
		p->next = NULL;
		L->next = p;
		L = L->next;
		p = new List;
		cin >> tmp;
	}
}


void reverse_print(List *L)
{
	if (L->next != NULL&&L != NULL)
		reverse_print(L->next);
	cout << L->data << " ";
}

int main()
{
	List *L = new List;
	L->data = 0;
	L->next = NULL;
	create(L);
	reverse_print(L);
	cout << endl;
	return 0;
}