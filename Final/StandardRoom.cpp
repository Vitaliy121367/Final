#include "StandardRoom.h"

Rooms::StandardRoom::StandardRoom()
{
	exitToSea = 0;
}

Rooms::StandardRoom::StandardRoom(int id, int num, bool free, int number, Date inhabited, int days, double priceDay, bool exitToSea):Room(id, num, free, number, inhabited, days, priceDay)
{
	this->exitToSea = exitToSea;
}

bool Rooms::StandardRoom::getExitToSea() const
{
	return exitToSea;
}

bool Rooms::StandardRoom::isEmpty() const
{
	return id != 0 && num != 0 && number != 0 && days != 0 && priceDay != 0;
}

void Rooms::StandardRoom::infoFile(ofstream& file)const
{
	file << "StandardRoom" << endl;
	file << id << endl;
	file << num << endl;
	file << free << endl;
	file << number << endl;
	file << inhabited.getDay() << " " << inhabited.getMonth() << " " << inhabited.getYear() << " " << endl;
	file << days << endl;
	file << priceDay << endl;
	file << exitToSea << endl << endl;
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

void Rooms::StandardRoom::showInfo() const
{
	cout << "\tStandardRoom" << endl;
	cout << "Id: " << id << endl;
	cout << "Num: " << num << endl;
	cout << "Number: " << number << endl;
	cout << "Inhabited: " << inhabited << endl;
	cout << "Evicted: " << inhabited + days << endl;
	cout << "Days: " << days << endl;
	cout << "Price day: " << priceDay << endl;
	cout << "Exit To Sea: " << (exitToSea ? "Yes" : "No") << endl;
	cout << "Free: " << (free ? "Yes" : "No") << endl;
}

ostream& Rooms::operator<<(ostream& os, const StandardRoom& r)
{
	os << "\tStandardRoom" << endl
		<< "Id: " << r.id << endl
		<< "Num: " << r.num << endl
		<< "Free: " << r.free << endl
		<< "Number: " << r.number << endl
		<< "Inhabited: " << r.inhabited << endl
		<< "Evicted: " << r.inhabited + r.days << endl
		<< "Days: " << r.days << endl
		<< "Price day: " << r.priceDay << endl
		<< "Exit To Sea: " << r.exitToSea << endl << endl;
	return os;
}