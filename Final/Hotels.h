#pragma once
#include "StandardRoom.h"
#include "SemiLuxRoom.h"
#include "LuxRoom.h"
#include "RoomException.h"
#include <vector>
#include <algorithm>
using namespace std;
namespace Rooms 
{
	class Hotels
	{
		vector<Room*>Hotel;
	public:
		Hotels();
		~Hotels();

		void addRoom(Room* obj);
		void delRoom(int i);
		void editRoom(int i);
		void searchRoom();
		void sortRoom();
		void printToFile();
		void showListHotel()const;
	};
}

