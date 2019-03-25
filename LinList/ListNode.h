#pragma once
template<class DataType>
class LinList;

template<class DataType>
class ListNode
{
	friend class LinList<DataType>;
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

};