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

		int* temp = new int[count + 1];  //ha �j elem �rkezik meg kell n�velni a t�mb m�ret�t
		for (unsigned int i = 0; i < count; i++)
		{
			temp[i] = data[i];//m�soljuk �t az adatokat az �j t�mbbe
		}
		temp[count] = item; //tegy�k az �j elemet a t�mb v�g�re//FIFO
		++count; //megadja h�ny elem van a t�mbben
		delete[] data;
		data = temp;//??
	}

	else //ha az elemek sz�ma nem nagyobb mint a max m�ret
	{
		data[count] = item; //ne feledj�k, h a count az elej�n nulla
		count++; // a beker�l egy elem akkor sz�ml�l� eggyel n�
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
