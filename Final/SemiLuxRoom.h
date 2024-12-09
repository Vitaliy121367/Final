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
		double sqBalcony;
		bool miniBar;
	public:
		SemiLuxRoom();
		SemiLuxRoom(int id, int num, int number, Date inhabited, int days, double priceDay, bool exitToSea, double sqBalcony, bool miniBar);

		double getSqBalcony()const;
		bool getMiniBar()const;

		void setSqBalcony(double sqBalcony);

		virtual void showInfo()const override;
		virtual double getFullPrice()const override;
	};
}