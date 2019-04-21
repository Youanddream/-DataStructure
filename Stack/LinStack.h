template <class T>
class LinStack
{
private:
	StackNode<T> *head;
	int size;
public:
	LinStack();
	~LinStack();
	void Push(const T& item);
	T Pop();
	T GetTop()const;
	int NotEmpty();

};

