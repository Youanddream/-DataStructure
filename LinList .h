#pragma once
#include<iostream>
using namespace std;

template<class DataType>
class LinList;

template<class DataType>
class ListNode
{
private:
	ListNode<DataType>* next;
	DataType data;
public:
	ListNode(ListNode<DataType>* ptrNext = NULL)
	{
		next = ptrNext;
	}

	ListNode(const DataType& item, ListNode<DataType>* perNext = NULL)
	{
		data = item;
		next = perNext;
	}

	~ListNode() {};
	friend class LinList<DataType>;
};


template<class DataType>
class Linlist
{
private:
	ListNode<DataType>* head;
	int size;
	ListNode<DataType>* Index(int i);

public:
	Linlist();
	~Linlist();

	int Size() const;
	void Insert(const DataType& item, int i);
	DataType Delete(int i);
	DataType GetData(int i);
	DataType InversionToNew();
	void Inversion();
};

template<class DataType>
Linlist<DataType>::Linlist()
{
	head = new ListNode<DataType>();
	size = 0;
}

template<class DataType>
Linlist<DataType>::~Linlist()
{
	ListNode<DataType> *p, *q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	size = 0;
	head = NULL;
}


template<class DataType>
ListNode<DataType>* Linlist<DataType>::Index(int i)
{
	if (i<-1 || i>size - 1)
	{
		cout << "参数越界！";
		exit（0）;
	}

	if (i == -1)
		return head;

	ListNode<DataType>* p = head->next;
	int j = 0;
	while (p != NULL && j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}


template<class DataType>
int Linlist<DataType>::Size() const
{
	return size;
}

template<class DataType>
void Linlist<DataType>::Insert(const DataType& item, int i)
{
	if (i<0 || i>size)
	{
		cout << "参数越界！";
		exit（0）;
	}
	ListNode<DataType> *p = Index(i - 1);
	ListNode<DataType> *q = new ListNode<DataType>(item, p->next);
	p->next = q;
	size++;
}

template<class DataType>
DataType LinList<DataType>::Delete(int i)
{
	if (size == 0)
	{
		cout<<"链表空，无可删除元素！"
	}

	ListNode<DataType> *s,*p=Index(i-1);
	s=p->next;
	p->next=p-next->next->next;
	DataType x=s->data;
	size--;
	return x;
}

template<class DataType>
DataType LinList<DataType>::GetData(int i)
{
	if(i<0||i>size-1)
	{
		cout<<"参数越界！";
		exit(0);
	}
	ListNode<DataType>  *p=Index(i);
	return p->data;
}


//倒置到新的linlist
template<class Datatype>
DataType LinList<DataType>::InversionToNew()
{
	LinList *b;
	for(int i=size,j=0,i>0,i--,j++)
	{
		ListNode *p=Index(i);
		b.Insert(p->data,j);
	}
	return b->head;
}

//就地倒置
template<class DataType>
void  LinList<DataType>::Inversion()
{
	for(int i=size,j=0,i<j;i--,j++)
	{
		ListNode *p,*q=Index(i);
		DataType tmp;
		tmp=q->data;
		p=Index(j);
		p->data=tmp;
	}
}