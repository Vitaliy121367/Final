#include "Hotels.h"

Rooms::Hotels::Hotels()
{
	ifstream file("hotelRoom.txt");
	if (file.is_open()) {
		string type = "";
		while (!file.eof())
		{
			Room* p = nullptr;
			file >> type;
			file.get();
			if (type == "StandardRoom")
			{
				p = new StandardRoom();
				p->load(file);
				Hotel.push_back(p);
			}
			else if (type == "SemiLuxRoom")
			{
				p = new SemiLuxRoom();
				p->load(file);
				Hotel.push_back(p);
			}
			else if (type == "LuxRoom")
			{
				p = new LuxRoom();
				p->load(file);
				Hotel.push_back(p);
			}
			else
			{
				cout << "Error!!!\n";
			}
		}
		file.close();
	}
}

Rooms::Hotels::~Hotels()
{

}

void Rooms::Hotels::addRoom(Room* obj)
{
	if (obj != nullptr) 
	{
		Hotel.push_back(obj);
	}
}

void Rooms::Hotels::delRoom(int i)
{
	i--;
	if (!Hotel.empty())
	{
		Hotel.erase(Hotel.begin() + i);
	}
}

void Rooms::Hotels::editRoom(int i)
{
	if (!Hotel.empty())
	{
	}
}

void Rooms::Hotels::printToFile()
{
	ofstream file("hotelRoom.txt");
	if (file.is_open()) 
	{
		for (int i = 0; i < Hotel.size(); i++)
		{
			if (Hotel[i]->isEmpty())
			{
				Hotel[i]->infoFile(file);
			}
		}
		file.close();
	}
}

void Rooms::Hotels::showListHotel() const
{
	for (int i = 0; i < Hotel.size(); i++)
	{
		if (Hotel[i]->getNum() != 0)
		{
			Hotel[i]->showInfo();
			cout << endl;
		}
	}
}