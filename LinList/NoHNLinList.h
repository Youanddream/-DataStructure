#pragma once
#include<iostream>
#include<stdlib.h>
#include "ListNode.h"
using namespace std;


template<class DataType>
class NoHNLinList
{
private:
	ListNode<DataType>* head;
	int size;
	ListNode<DataType>* Index(int i);

public:
	NoHNLinList();
	~NoHNLinList();

	int Size() const;
	void Insert(const DataType& item, int i);
	DataType Delete(int i);
	DataType GetData(int i);
};

template<class DataType>
NoHNLinList<DataType>::NoHNLinList()
{
	head = new ListNode<DataType>();
	size = 0;
}

template<class DataType>
NoHNLinList<DataType>::~NoHNLinList()
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
int NoHNLinList<DataType>::Size() const
{

	return size;
}

template<class DataType>
ListNode<DataType>* NoHNLinList<DataType>::Index(int i)
{
	if (i<-1 || i>size - 1)
	{
		cout << "参数越界！index";
		//exit（0）;
	}
	if (i == -1)
		return head;
	if (i == 0)
	{
		return head->next;
	}
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
void NoHNLinList<DataType>::Insert(const DataType & item, int i)
{
	if (i<0 || i>size)
	{
		cout << "参数越界！insert";
		//exit（0）;
	}
	if (i == 0)
	{
		ListNode<DataType> *p;
		p = head->next;
		ListNode<DataType> *q = new ListNode<DataType>(item,p);
		head->next = q;
		size++;
		return;
	}

	ListNode<DataType> *p = Index(i - 1);
	ListNode<DataType> *q = new ListNode<DataType>(item, p->next);
	p->next = q;
	size++;
}

template<class DataType>
DataType NoHNLinList<DataType>::Delete(int i)
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
	if (i == 0)
	{
		DataType x = head->data;
		head->next = head->next->next;
		size--;
		return x;
	}

	ListNode<DataType> *s, *p = Index(i - 1);
	s = p->next;
	p->next = p ->next->next;
	DataType x = s->data;
	size--;
	return x;
}

template<class DataType>
DataType NoHNLinList<DataType>::GetData(int i)
{
	if (i<0 || i>size - 1)
	{
		cout << "参数越界！getdata";
		//exit(0);
	}
	ListNode<DataType> *p = Index(i);
	return p->data;
}