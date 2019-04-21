template <class T> class LinStack;

template <class T>
class StackNode
{
	friend class LinStack<T>;
private:
	T data;
	StackNode<T> *next;
public:
	StackNode(StackNode<T> *ptrNext=NULL){next=ptrNext;}
	StackNode(const T& item ,StackNode<T> *ptrNext=NULL){data=item;next=ptrNext;}
	~StackNode(){};


};