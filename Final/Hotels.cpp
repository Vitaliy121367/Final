#include "Hotels.h"

Rooms::Hotels::Hotels()
{
	Room* p = nullptr;
	ifstream file("hotelRoom.txt");
	if (file.is_open()) {
		string type = "";
		while (!file.eof())
		{
			file >> type;
			file.get();
			if (type == "StandardRoom")
			{
				p = new StandardRoom();
				p->load(file);
				Hotel.push_back(p);
				if (p->getFree() == 1) { freeRoom.push_back(p); }
				else { unfreeRoom.push_back(p); }
			}
			else if (type == "SemiLuxRoom")
			{
				p = new SemiLuxRoom();
				p->load(file);
				Hotel.push_back(p);
				if (p->getFree() == 1) { freeRoom.push_back(p); }
				else { unfreeRoom.push_back(p); }
			}
			else if (type == "LuxRoom")
			{
				p = new LuxRoom();
				p->load(file);
				Hotel.push_back(p);
				if (p->getFree() == 1) { freeRoom.push_back(p); }
				else { unfreeRoom.push_back(p); }
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
	for (int i = 0; i < Hotel.size(); i++)
	{
		delete Hotel[i];
	}
}

void Rooms::Hotels::addRoom(Room* obj)
{
	if (obj != nullptr) 
	{
		Hotel.push_back(obj);
		if (obj->getFree() == 1) { freeRoom.push_back(obj); }
		else { unfreeRoom.push_back(obj); }
	}
}

void Rooms::Hotels::showListHotel() const
{
	for (int i = 0; i < Hotel.size(); i++)
	{
		Hotel[i]->showInfo();
		cout << endl;
	}
}

void Rooms::Hotels::showListFreeRoom() const
{
	for (int i = 0; i < freeRoom.size(); i++)
	{
		freeRoom[i]->showInfo();
		cout << endl;
	}
}

void Rooms::Hotels::showListUnfreeRoom() const
{
	for (int i = 0; i < unfreeRoom.size(); i++)
	{
		unfreeRoom[i]->showInfo();
		cout << endl;
	}
}
