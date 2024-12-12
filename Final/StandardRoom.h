#pragma once
#include "Room.h"
#include <iostream>
#include <fstream>
#include "Date.h"
using namespace std;
namespace Rooms 
{
	class StandardRoom : public Room
	{
	protected:
		bool exitToSea;
	public:
		StandardRoom();
		StandardRoom(int id, int num, bool free, int number, Date inhabited, int days, double priceDay, bool exitToSea);
	
		bool getExitToSea()const;

		virtual bool isEmpty()const override;
		virtual void infoFile(ofstream& file)const override;

		friend ostream& operator << (ostream& os, const StandardRoom& r);
		virtual double getFullPrice()const override; 
		virtual void showInfo()const override;
		virtual void load(ifstream& file)override 
		{
			file >> id;
			file >> num;
			file >> free;
			file >> number; 
			int d = 0, m = 0, y = 0;
			file >> d >> m >> y;
			inhabited.setYear(y);
			inhabited.setMonth(m);
			inhabited.setDay(d);
			file >> days;
			file >> priceDay;
			file >> exitToSea;
			file.get();
		}
	};
}
