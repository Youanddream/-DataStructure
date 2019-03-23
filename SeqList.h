#pragma once
template <class DataType>
class SeqList
{
protected:
	DataType * list;
	int maxSize;
	int size;

public:
	SeqList(int max = 0);
	~SeqList();
	int Size() const;
	void Insert(const DataType& item, int i);
	DataType Delete(const int i);
	DataType GetData(int i) const;
};

template <class DataType>
SeqList::SeqList(int max)
{
	maxSize = max;
	size = 0;
	list = new DataType[maxSize];
}

template <class DataType>
SeqList::~SeqList()
{
	delete[]list;
}

template <class DataType>
int SeqList::Size() const
{
	return size;
}

template <class DataType>
void SeqList::Insert(const DataType& item, int i)
{
	if (size == maxSize)
	{
		cout << "顺序表已满，无法插入！";
		exit(0);
	}

	if (i<0 || i>size)
	{
		cout << "参数越界！";
		exit(0);
	}

	for (int j = size; j>i; j--)
	{
		list[j] = list[j - 1];
		list[i] = item;
		size++;
	}
}

template <class DataType>
DataType SeqList::Delete(const int i)
{
	if (size == 0)
	{
		cout << "顺序表已空，无法可删除元素！";
		exit(0);
	}

	if (i<0 || i>size - 1)
	{
		cout << "参数越界！";
		exit(0);
	}

	DataType x = list[i];

	for (int j = i; j<size - 1; j++)
	{
		list[j] = list[j + 1];
		size--;
		return x;
	}
}

template <class DataType>
DataType SeqList::GetData(int i) const
{
	if (i<0 || i>size - 1)
	{
		cout << "参数越界！";
		exit(0);
	}
	return list[i];
}