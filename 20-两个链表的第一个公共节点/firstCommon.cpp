#include <iostream>
#include <algorithm>
using namespace std;


class List{
public:
  int val;
  List *next;
};

void create(List *L)
{
	List* p = new List;
	int data;
	cin>>data;
	p->val = data;
	while(data!=0)
	{
		p->next = NULL;
		L->next = p; 
		L = L->next;
		p = new List;
		cin>>data;
		p->val = data;
	}
}

int getLength(List *L)
{
	List *p = L->next;
	int count = 0;
	while(p)
	{
		count++;
		p=p->next;
	}
	return count;
}

int find_x(List *L1,List *L2)
{
	int len1 = 0,len2 = 0;
	List *p1 = L1->next;
	List *p2 = L2->next;
	while(p1)
	{
		len1++;
		p1=p1->next;
	}
	while(p2)
	{
		len2++;
		p2=p2->next;
	}
	int bias = (len1>len2?len1:len2)-(len1<len2?len1:len2);
	p1=L1->next;
	p2=L2->next;
	if(len1<len2)
	{
		for(int i=0;i<bias;++i)
		{
             p2=p2->next;			
		}
	}
	else if(len1>len2)
	{
		for(int i=0;i<bias;++i)
			{
				 p1=p1->next;			
			}	
	}
	while(p1&&p2)
	{
		if(p1->val==p2->val)
			break;
		p1=p1->next;
		p2=p2->next;
	}
	return p1->val;
}

void show(List *L)
{
	List *p = L->next;
	while(p)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	List *L1 = new List;
	List *L2 = new List;
	L1->next = NULL;
	L2->next = NULL;
	create(L1);
	create(L2);
	cout<<find_x(L1,L2)<<endl;
	return 0;
}