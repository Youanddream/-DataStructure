#pragma once
#include<iostream>
#include<stdlib.h>
#include "DoubleListNode.h"
using namespace std;



template<class DataType>
class DC_LinList
{
private:
	DC_ListNode<DataType>* head;
	int size;
	DC_ListNode<DataType>* Index(int i);

public:
	DC_LinList();
	~DC_LinList();

	int Size() const;
	void Insert(const DataType& item, int i);
	DataType Delete(int i);
	DataType GetData(int i);
	
};

template<class DataType>
DC_LinList<DataType>::DC_LinList()
{
	head = new DC_ListNode<DataType>();
	head->next = head;
	size = 0;
}

template<class DataType>
DC_LinList<DataType>::~DC_LinList()
{
	DC_ListNode<DataType> *p, *q;
	p = head;
	while (p != head)
	{
		q = p;
		p = p->next;
		delete q;
	}
	size = 0;
	head = NULL;
}


template<class DataType>
DC_ListNode<DataType> * DC_LinList<DataType>::Index(int i)
{
	if (i<-1 || i>size - 1)
	{
		cout << "参数越界！index";
		//exit（0）;
	}

	if (i == -1)
		return head;

	DC_ListNode<DataType>* p = head->next;
	int j = 0;
	while (p != head && j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}


template<class DataType>
int DC_LinList<DataType>::Size() const
{
	return size;
}

template<class DataType>
void DC_LinList<DataType>::Insert(const DataType& item, int i)
{
	if (i<0 || i>size)
	{
		cout << "参数越界！insert";
		//exit（0）;
	}
	DC_ListNode<DataType> *p = Index(i - 1);
	DC_ListNode<DataType> *q = new DC_ListNode<DataType>(item, p,p->next);
	p->next->prior = q;  
	p->next = q;
	size++;
}

template<class DataType>
DataType DC_LinList<DataType>::Delete(int i)
{
	if (size == 0)
	{
		cout << "链表空，无可删除元素！" << endl;
		//exit(0);
	}
	if (i<0 || i>size - 1)
	{
		cout << "参数i越界！delete";
		//exit(0);
	}

	DC_ListNode<DataType> *s, *p = Index(i - 1);
	s = p->next;
	p->next = p->next->next;
	p->next->prior = p;
	DataType x = s->data;
	size--;
	return x;
}

template<class DataType>
DataType DC_LinList<DataType>::GetData(int i)
{
	if (i<0 || i>size - 1)
	{
		cout << "参数越界！getdata";
		//exit(0);
	}
	DC_ListNode<DataType> *p = Index(i);
	return p->data;
}