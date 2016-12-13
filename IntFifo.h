
#pragma once
class IntFifo {
private:
	//mutató az elemeknek lefoglalt hely elejére
	int* data;
	//A fifo számára lefoglalt memória mérete elemszámban
	unsigned int size;
	//A fifoban aktuálisan lévõ elemek száma
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
	//igaz, ha fifo üres
	bool Isempty();
};
