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
	public:
		SemiLuxRoom();
		SemiLuxRoom(int id, int num, int number, Date inhabited, int days, double priceDay, bool exitToSea, double sqBalcony);

		double getSqBalcony()const;

		void setSqBalcony(double sqBalcony);

		virtual void showInfo()const override;
		virtual double getFullPrice()const override;
	};
}