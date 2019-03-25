#pragma once
#include<iostream>
#include<stdlib.h>
#include "ListNode.h"
using namespace std;



template<class DataType>
class CirLinList
{
private:
	ListNode<DataType>* head;
	int size;
	ListNode<DataType>* Index(int i);

public:
	CirLinList();
	~CirLinList();

	int Size() const;
	void Insert(const DataType& item, int i);
	DataType Delete(int i);
	DataType GetData(int i);
	//CirLinList InversionToNew();
	//void Inversion();
	//CirLinList<DataType> operator =(CirLinList<DataType> &a) { head = a.head; size = a.size; }
};

template<class DataType>
CirLinList<DataType>::CirLinList()
{
	head = new ListNode<DataType>();
	head->next = head;
	size = 0;
}

template<class DataType>
CirLinList<DataType>::~CirLinList()
{
	ListNode<DataType> *p, *q;
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
ListNode<DataType> * CirLinList<DataType>::Index(int i)
{
	if (i<-1 || i>size - 1)
	{
		cout << "����Խ�磡index";
		//exit��0��;
	}

	if (i == -1)
		return head;

	ListNode<DataType>* p = head->next;
	int j = 0;
	while (p != head && j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}


template<class DataType>
int CirLinList<DataType>::Size() const
{
	return size;
}

template<class DataType>
void CirLinList<DataType>::Insert(const DataType& item, int i)
{
	if (i<0 || i>size)
	{
		cout << "����Խ�磡insert";
		//exit��0��;
	}
	ListNode<DataType> *p = Index(i - 1);
	ListNode<DataType> *q = new ListNode<DataType>(item, p->next);
	p->next = q;
	size++;
}

template<class DataType>
DataType CirLinList<DataType>::Delete(int i)
{
	if (size == 0)
	{
		cout << "����գ��޿�ɾ��Ԫ�أ�" << endl;
		//exit(0);
	}
	if (i<0 || i>size - 1)
	{
		cout << "����iԽ�磡delete";
		//exit(0);
	}

	ListNode<DataType> *s, *p = Index(i - 1);
	s = p->next;
	p->next = p ->next->next;
	DataType x = s->data;
	size--;
	return x;
}

template<class DataType>
DataType CirLinList<DataType>::GetData(int i)
{
	if (i<0 || i>size - 1)
	{
		cout << "����Խ�磡getdata";
		//exit(0);
	}
	ListNode<DataType> *p = Index(i);
	return p->data;
}

////���õ��µ�linlist
//template<class DataType>
//CirLinList<DataType> CirLinList<DataType>::InversionToNew()
//{
//	CirLinList<DataType> b;
//	for (int i = size - 1, j = 0; i>0; i--, j++)
//	{
//		ListNode<DataType> *p = Index(i);
//		b.Insert(p->data, j);
//	}
//	return b->head;
//}
//
//
////�͵ص���
//template<class DataType>
//void CirLinList<DataType>::Inversion()
//{
//	for (int i = size - 1, j = 0; j<i; i--, j++)
//	{
//		ListNode<DataType> *p, *q;
//		p = Index(j);
//		q = Index(i);
//		DataType tmp;
//		tmp = q->data;
//		q->data = p->data;
//		p->data = tmp;
//	}
//}