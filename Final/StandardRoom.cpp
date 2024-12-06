#include "StandardRoom.h"

Rooms::StandardRoom::StandardRoom()
{
	exitToSea = 0;
}

Rooms::StandardRoom::StandardRoom(int num, int number, Date inhabited, int days, double priceDay, bool exitToSea):Room(num, number, inhabited, days, priceDay)
{
	this->exitToSea = exitToSea;
}

bool Rooms::StandardRoom::getExitToSea() const
{
	return exitToSea;
}

void Rooms::StandardRoom::showInfo() const
{
	cout << "Num: " << num << endl;
	cout<< "Number: "<< number << endl;
	cout << "Inhabited: " << inhabited << endl;
	cout << "Evicted: " << inhabited + days << endl;
	cout<< "Days: "<< days << endl;
	cout<< "Price day: "<< priceDay << endl;
	cout<< "Exit To Sea: "<< (exitToSea ? "Yes" : "No") << endl;
}

double Rooms::StandardRoom::getFullPrice() const
{
	double fullPrice = 0;
	fullPrice = priceDay * days;
	if (days>10)
	{
		fullPrice = fullPrice * 0.75;
	}
	if (exitToSea==1)
	{
		fullPrice += fullPrice * 0.25;
	}
	return fullPrice;
}
