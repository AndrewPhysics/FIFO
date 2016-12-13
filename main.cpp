#include <iostream>
#include "IntFifo.h"
using namespace std;

int main() {


	IntFifo fifo(10);// ez mi

	const int m = 10;


	for (int i = 0; i < m; i++)
	{
		fifo.Put(i);
	}
	int i;
	for (int i = 0; i < m; i++)
	{
		cout << fifo.Get(i) << endl;
	}
	system("pause");
	return 0;
}