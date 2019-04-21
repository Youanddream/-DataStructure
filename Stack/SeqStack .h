const int MaxStackSize=100;
template <class T>
class SeqStack
{
private:
	T data[MaxStackSize];
	int top;
public:
	SeqStack(){top=0;};
	~SeqStack(){};
	void Push(const T item);
	T Pop();
	T GetTop()const;
	int NotEmpty()const{return top!=0;}
};


template <class T>
void SeqStack<T>::Push(const T item)
{
	if(top==MaxStackSize)
	{
		cout<<"堆栈已满"<<endl;
		exit(0);
	}
	data[top]=item;
	top++;
}

template <class T>
T SeqStack<T>::Pop()
{
	if(top==0)
	{
		cout<<"堆栈已空"<<endl;
		exit(0);
	}
	top--;
	return data[top];
}

template <class T>
T SeqStack<T>::GetTop()const
{
	if(top==0)
	{
		cout<<"堆栈已空"<<endl;
		exit(0);
	}
	return data[top-1];
}

