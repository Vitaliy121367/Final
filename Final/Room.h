#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include "Date.h"
using namespace std;
namespace Rooms {
	class Room
	{
	protected:
		long identifier;
		int num;
		int number;
		Date inhabited;
		int days;
		double priceDay;
	public:
		Room();
		Room(int num, int number, Date inhabited, int days, double priceDay);
		virtual ~Room();

		long getIdentifier()const;
		int getNum()const;
		int getNumber()const;
		Date getInhabited()const;
		int getDays()const;
		double getPriceDay()const;

		void setDays(int days);
		void setPriceDay(double priceDay);

		virtual void showInfo()const = 0;
		virtual double getFullPrice()const = 0;
	};
}