#pragma once
#include "StandardRoom.h"
#include "SemiLuxRoom.h"
#include <iostream>
#include <fstream>
#include "Date.h"
using namespace std;
namespace Rooms
{
	class LuxRoom : public SemiLuxRoom
	{
	protected:
		double wifiSpeed;
	public:
		LuxRoom();
		LuxRoom(int id, int num, bool free, int number, Date inhabited, int days, double priceDay, bool exitToSea, double sqBalcony, bool miniBar, double wifiSpeed);

		double getWifiSpeed()const;

		void setWifiSpeed(double wifiSpeed);

		virtual bool isEmpty()const override;
		virtual void infoFile(ofstream& file)const override;

		friend ostream& operator << (ostream& os, const LuxRoom& r);
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
			file >> sqBalcony;
			file >> miniBar;
			file >> wifiSpeed;
			file.get();
		}
	};
}
