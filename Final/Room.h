#pragma once
#include <iostream>
#include <fstream>
#include "Date.h"
using namespace std;
namespace Rooms {
	class Room
	{
		int identifier;
		int num;
		int number;
		Date race;
		int days;
		double priceDay;
		bool exitToTheSea;
	public:
		Room();
		Room(int identifier, int num, int number, Date race, int days, double priceDay, bool exitToTheSea);
		virtual ~Room();

		int getIdentifier()const;
		int getNum()const;
		int getNumber()const;
		Date getRace()const;
		int getDays()const;
		double getPriceDay()const;
		bool getExitToTheSea()const;

		void setDays(int days);
		void setPriceDay(bool exitToTheSea);

		virtual void showInfo()const = 0;
		virtual void showFullPrice()const = 0;
		virtual void load(ifstream& file) = 0;
	};
}