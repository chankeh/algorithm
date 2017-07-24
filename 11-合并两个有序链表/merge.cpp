#include <iostream>

using namespace std;

class List
{
public:
	int data;
	List *next;
};

void create(List *L)
{
	List *p = new List;
	cin >> p->data;
	while (p->data != 0)
	{
		p->next = NULL;
		L->next = p;
		L = L->next;
		p = new List;
		cin >> p->data;
	}
	p->next = NULL;
}

List* merge(List* L1, List* L2)
{
	if (L1 == NULL)
		return L2;
	else if (L2 == NULL)
		return L1;
	List* pMerge = NULL;
	if (L1->data<L2->data)
	{
		pMerge = L1;
		pMerge->next = merge(L1->next, L2);
	}
	else
	{
		pMerge = L2;
		pMerge->next = merge(L1, L2->next);
	}
	return pMerge;
}

void show(List *L)
{
	List* p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}


int main()
{
	List* L1 = new List;
	List* L2 = new List;
	List* lMerge = new List;
	L1->next = NULL;
	L2->next = NULL;
	lMerge = NULL;
	create(L1);
	show(L1);
	create(L2);
	show(L2);
	lMerge = merge(L1, L2);
	show(lMerge);
	return 0;
}