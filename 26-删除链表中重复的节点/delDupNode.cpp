#include <iostream>
#include <algorithm>
using namespace std;


class ListNode{
public:
  int val;
  ListNode *next;
};

void create(ListNode *L)
{
	ListNode* p = new ListNode;
	int data;
	cin>>data;
	p->val = data;
	while(data!=0)
	{
		p->next = NULL;
		L->next = p; 
		L = L->next;
		p = new ListNode;
		cin>>data;
		p->val = data;
	}
}


ListNode* delWholDulRecur(ListNode *pHead)
{
   if(pHead==NULL||pHead->next==NULL)
        return pHead;
	if(pHead->val==pHead->next->val)
	{
		ListNode* pNode = pHead->next;
		while(pNode!=NULL&&pNode->val==pHead->val)
		{
			pNode = pNode->next;
		}
		return delWholDulRecur(pNode);
	}
	else
	{
		pHead->next = delWholDulRecur(pHead->next);
	}
	return pHead;
}

void delWholDul(ListNode *L)
{
	ListNode *pre = L,*p = L->next,*q,*r;
	while(p!=NULL&&p->next!=NULL)
	{
		if(p->val==p->next->val)
		{
			while(p->val==p->next->val&&p!=NULL&&p->next!=NULL)
			{
				r = p;
				q = p->next;
				p->next = q->next;
				delete q;
			}
			pre->next = p->next;
			delete r;
			p = pre->next;
		}
		else
		{
			p = p->next;
			pre = pre->next;
		}
	}
}

void delNode(ListNode *L)//去重代码
{
	ListNode *p = L->next,*q;
	while(p!=NULL&&p->next!=NULL)
	{
		if(p->val==p->next->val)
		{
			q = p->next;
			p->next=q->next;
			free(q);
		}
		else
		{
			p=p->next;
		}
	}
}

void show(ListNode *L)
{
	ListNode *p = L->next;
	while(p)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	ListNode *L1 = new ListNode;
	ListNode *L2 = NULL;
	L1->next = NULL;
	create(L1);
   // delNode(L1);
   //delWholDul(L1);
   L2 = delWholDulRecur(L1);
	show(L2);
	return 0;
}