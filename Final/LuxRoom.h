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
		LuxRoom(int id, int num, int number, Date inhabited, int days, double priceDay, bool exitToSea, double sqBalcony, bool miniBar, double wifiSpeed);

		double getWifiSpeed()const;

		void setWifiSpeed(double wifiSpeed);
		
		virtual void showInfo()const override;
		virtual double getFullPrice()const override;
	};
}
