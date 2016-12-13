
#pragma once
class IntFifo {
private:
	//mutat� az elemeknek lefoglalt hely elej�re
	int* data;
	//A fifo sz�m�ra lefoglalt mem�ria m�rete elemsz�mban
	unsigned int size;
	//A fifoban aktu�lisan l�v� elemek sz�ma
	unsigned int count;

public:

	IntFifo();

	IntFifo(unsigned int size);

	IntFifo(const IntFifo& size);

	//destruktor
	~IntFifo();

	void Put(int item);

	bool Get(int& item);

	
	void Print();

	int Count() { return count; }
	//igaz, ha fifo �res
	bool Isempty();
};
