#pragma once
#include "StandardRoom.h"
#include "SemiLuxRoom.h"
#include "LuxRoom.h"
#include <vector>
#include <algorithm>
using namespace std;
namespace Rooms 
{
	class Hotels
	{
		vector<Room*>Hotel;
		vector<Room*>freeRoom;
		vector<Room*>unfreeRoom;
	public:
		Hotels();
		~Hotels();

		void addRoom(Room* obj);
		void printToFile();
		void showListHotel()const;
		void showListFreeRoom()const;
		void showListUnfreeRoom()const;
	};
}

