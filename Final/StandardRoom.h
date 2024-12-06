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
		bool exitToSea;
	public:
		StandardRoom();
		StandardRoom(int num, int number, Date inhabited, int days, double priceDay, bool exitToSea);
	
		bool getExitToSea()const;

		virtual void showInfo()const override;
		virtual double getFullPrice()const override;
	};
}
