#pragma once
#include "StandardRoom.h"
#include <iostream>
#include <fstream>
#include "Date.h"
using namespace std;
namespace Rooms
{
	class SemiLuxRoom : public StandardRoom
	{
	protected:
		double sqBalcony;
		bool miniBar;
	public:
		SemiLuxRoom();
		SemiLuxRoom(int num, bool free, int number, Date inhabited, int days, double priceDay, bool exitToSea, double sqBalcony, bool miniBar);

		double getSqBalcony()const;
		bool getMiniBar()const;

		void setMiniBar(bool miniBar);

		virtual bool isEmpty()const override;
		virtual void infoFile(ofstream& file)const override;

		friend ostream& operator << (ostream& os, const SemiLuxRoom& r);
		friend istream& operator >> (istream& is, SemiLuxRoom& r);

		virtual double getFullPrice()const override;
		virtual void showInfo()const override;
		virtual void load(ifstream& file)override
		{
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
			file >> sqBalcony;
			file >> miniBar;
			file.get();
		}
	};
}