#include "IntFifo.h"
#include <iostream>
using namespace std;

IntFifo::IntFifo()
{
	data = NULL;
	size = 0;
	count = 0;
}
//---------------------------------
IntFifo::IntFifo(unsigned int size)
{
	data = NULL;
	this->size = size;
	count = 0;
	if (size != 0) {
		data = new int[size];
	}
}
//------------------------------------
IntFifo::IntFifo(const IntFifo& fifo)
{
	size = fifo.size;
	count = fifo.count;
	unsigned int actualSize = (size > count) ? size : count; 
	if (fifo.data == NULL)
	{
		data = NULL;
	}
	else
	{
		data = new int[actualSize];
		for (unsigned int i = 0; i < count; i++)
		{
			data[i] = fifo.data[i];
		}
	}
}

IntFifo::~IntFifo()
{
	delete[] data;
}

void IntFifo::Put(int item)
{
	if (count >= size)
	{

		int* temp = new int[count + 1];  //ha új elem érkezik meg kell növelni a tömb méretét
		for (unsigned int i = 0; i < count; i++)
		{
			temp[i] = data[i];//másoljuk át az adatokat az új tömbbe
		}
		temp[count] = item; //tegyük az új elemet a tömb végére//FIFO
		++count; //megadja hány elem van a tömbben
		delete[] data;
		data = temp;//??
	}

	else //ha az elemek száma nem nagyobb mint a max méret
	{
		data[count] = item; //ne feledjük, h a count az elején nulla
		count++; // a bekerül egy elem akkor számláló eggyel nõ
	}
}
bool IntFifo::Get(int& item)
{
	if (count == 0)// ha count nulla nincs mit kivenni
	{
		fprintf(stderr, "Data request from an empty Fifo.\n");
		return false;
	}
	item = data[0];
	--count;
	if (size <= count)
	{
		if (count = 0)
		{
			delete[] data;
			data = NULL;
			return true;
		}
		int* temp = new int[count];
		for (unsigned int i = 0; i < count; i++)
			temp[i] = data[i + 1];
		delete[] data;
		data = temp;
	}
	else
	{
		for (unsigned int i = 0; i < count; i++)
		{
			data[i] = data[i + 1];
		}
	}
	return true;
}

bool IntFifo::Isempty() { return count == 0; }
