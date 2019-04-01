#include"SeqList.h"

int main()
{

	//²âÊÔexpand
	int a[6] = { 0,1,2,3,4,5 };
	SeqList<int> b(a,0,5);
	cout << b.GetData(5) << endl;
	b.InversionLocal();
	cout << b.GetData(5) << endl;
	b.Insert(9, 6);
	cout<<"size:"<<b.Size();
	cout << "maxsize:" << b.maxsize();


	
}