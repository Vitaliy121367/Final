#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include "Date.h"
using namespace std;
namespace Rooms {
	class Room
	{
	protected:
		static int counter;
		int id;
		int num;
		bool free;
		int number;
		Date inhabited;
		int days;
		double priceDay;
	public:
		Room();
		Room(int num, bool free, int number, Date inhabited, int days, double priceDay);
		virtual ~Room();

		int getId()const;
		int getNum()const;
		int getFree()const;
		int getNumber()const;
		Date getInhabited()const;
		int getDays()const;
		double getPriceDay()const;

		void setFree(bool free);
		void setDays(int days);
		void setPriceDay(double priceDay);

		virtual bool isEmpty()const = 0;
		virtual void infoFile(ofstream& file)const = 0;

		virtual double getFullPrice()const = 0;
		virtual void showInfo()const = 0;
		virtual void load(ifstream& file) = 0; 
	};
}