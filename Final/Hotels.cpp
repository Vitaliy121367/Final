#include "Hotels.h"

Rooms::Hotels::Hotels()
{
	ifstream file("hotelRoom.txt");
	if (file.is_open()) {
		string type = "";
		while (!file.eof())
		{
			Room* p = nullptr;
			file >> type;
			file.get();
			if (type == "StandardRoom")
			{
				p = new StandardRoom();
				p->load(file);
				Hotel.push_back(p);
			}
			else if (type == "SemiLuxRoom")
			{
				p = new SemiLuxRoom();
				p->load(file);
				Hotel.push_back(p);
			}
			else if (type == "LuxRoom")
			{
				p = new LuxRoom();
				p->load(file);
				Hotel.push_back(p);
			}
			else
			{
				cout << "Error!!!\n";
			}
		}
		file.close();
	}
	else {
		throw HotelException("txt not open");
	}
}

Rooms::Hotels::~Hotels()
{
	Hotel.erase(Hotel.begin(),Hotel.end());
}

void Rooms::Hotels::addRoom(Room* obj)
{
	if (obj->isEmpty())
	{
		Hotel.push_back(obj);
	}
	else {
		throw HotelException("empty");
	}
}

void Rooms::Hotels::delRoom(int i)
{
	i--;
	if (i<Hotel.size())
	{
		if (Hotel[i]->isEmpty())
		{
			Hotel.erase(Hotel.begin() + i);
		}
	}
	else
	{
		i++;
		throw HotelException(to_string(i)+" does not meet the limits");
	}
}

void Rooms::Hotels::editRoom(int i)
{
	i--;
	if (i < Hotel.size())
	{
		if (!Hotel.empty())
		{
			if (typeid(*Hotel[i]) == typeid(StandardRoom))
			{
				StandardRoom* p = dynamic_cast<StandardRoom*>(Hotel[i]);
				if (p != nullptr)
				{
					bool free;
					int days;
					double priceDay;
					cout << *p << endl << endl;

					cout << "New Free: ";
					cin >> free;
					p->setFree(free);
					cout << "New Days: ";
					cin >> days;
					p->setDays(days);
					cout << "New Price Day: ";
					cin >> priceDay;
					p->setPriceDay(priceDay);
				}
			}
			else if (typeid(*Hotel[i]) == typeid(SemiLuxRoom))
			{
				SemiLuxRoom* p = dynamic_cast<SemiLuxRoom*>(Hotel[i]);
				if (p != nullptr)
				{
					bool free;
					int days;
					double priceDay;
					bool miniBar;
					cout << *p << endl << endl;

					cout << "New Free: ";
					cin >> free;
					p->setFree(free);
					cout << "New Days: ";
					cin >> days;
					p->setDays(days);
					cout << "New Price Day: ";
					cin >> priceDay;
					p->setPriceDay(priceDay);
					cout << "New Mini Bar: ";
					cin >> miniBar;
					p->setMiniBar(miniBar);
				}

			}
			else if (typeid(*Hotel[i]) == typeid(LuxRoom))
			{
				LuxRoom* p = dynamic_cast<LuxRoom*>(Hotel[i]);
				if (p != nullptr)
				{
					bool free;
					int days;
					double priceDay;
					bool miniBar;
					double wifiSpeed;
					cout << *p << endl << endl;

					cout << "New Free: ";
					cin >> free;
					p->setFree(free);
					cout << "New Days: ";
					cin >> days;
					p->setDays(days);
					cout << "New Price Day: ";
					cin >> priceDay;
					p->setPriceDay(priceDay);
					cout << "New Mini Bar: ";
					cin >> miniBar;
					p->setMiniBar(miniBar);
					cout << "New WiFi Speed: ";
					cin >> miniBar;
					p->setWifiSpeed(miniBar);
				}
			}
		}
	}
	else
	{
		i++;
		throw HotelException(to_string(i) + " does not meet the limits");
	}
}

void Rooms::Hotels::buyReleaseRoom(int i)
{
	i--; 
	if (i < Hotel.size())
	{
		if (Hotel[i]->getFree())
		{
			Hotel[i]->setFree(0);
		}
		else
		{
			Hotel[i]->setFree(1);
		}
	}
	else
	{
		i++;
		throw HotelException(to_string(i) + " does not meet the limits");
	}
}

void Rooms::Hotels::searchRoom()
{
	if (!Hotel.empty())
	{
		int num;
		cout << "+--------------------------+\n";
		cout << "|   1 - Id                 |\n";
		cout << "|   2 - Free               |\n";
		cout << "|   3 - Unfree             |\n";
		cout << "|   4 - Date               |\n";
		cout << "|   5 - Number of people   |\n";
		cout << "|   6 - Number of days     |\n";
		cout << "|   7 - Standard Room      |\n";
		cout << "|   8 - Semi Lux Room      |\n";
		cout << "|   9 - Lux Room           |\n";
		cout << "+--------------------------+\n";
		cout << "Num: ";
		cin >> num;

		if (num == 1)
		{
			cout << "Id: ";
			cin >> num;
			if (num>0&&num<Hotel.size())
			{
				for (int i = 0; i < Hotel.size(); i++)
				{
					if (Hotel[i]->getId() == num && Hotel[i]->isEmpty())
					{
						Hotel[i]->showInfo();
						cout << endl;
						return;
					}
				}
				cout << "Not fiund\n";
			}
			else
			{
				throw HotelException(to_string(num) + " does not meet the limits");
			}
		}
		else if (num == 2)
		{
			for (int i = 0; i < Hotel.size(); i++)
			{
				if (Hotel[i]->getFree() == 1 && Hotel[i]->isEmpty())
				{
					Hotel[i]->showInfo(); 
					cout << endl;
				}
			}
		}
		else if (num == 3)
		{
			for (int i = 0; i < Hotel.size(); i++)
			{
				if (Hotel[i]->getFree() == 0 && Hotel[i]->isEmpty())
				{
					Hotel[i]->showInfo(); 
					cout << endl;
				}
			}
		}
		else if (num == 4)
		{
			Date d;
			cin >> d;
			for (int i = 0; i < Hotel.size(); i++)
			{
				if (Hotel[i]->getInhabited() == d && Hotel[i]->isEmpty())
				{
					Hotel[i]->showInfo(); 
					cout << endl;
				}
			}
		}
		else if (num == 5)
		{
			cout << "Number of people: ";
			cin >> num;
			for (int i = 0; i < Hotel.size(); i++)
			{
				if (Hotel[i]->getNumber() == num && Hotel[i]->isEmpty())
				{
					Hotel[i]->showInfo(); 
					cout << endl;
				}
			}
		}
		else if (num == 6)
		{
			cout << "Number of days: ";
			cin >> num;
			for (int i = 0; i < Hotel.size(); i++)
			{
				if (Hotel[i]->getDays() == num && Hotel[i]->isEmpty())
				{
					Hotel[i]->showInfo(); 
					cout << endl;
				}
			}
		}
		else if (num == 7)
		{
			for (int i = 0; i < Hotel.size(); i++)
			{
				if (typeid(*Hotel[i]) == typeid(StandardRoom) && Hotel[i]->isEmpty())
				{
					StandardRoom* p = dynamic_cast<StandardRoom*>(Hotel[i]);
					if (p != nullptr)
					{
						cout << *p << endl;
					}
				}
			}
		}
		else if (num == 8)
		{
			for (int i = 0; i < Hotel.size(); i++)
			{
				if (typeid(*Hotel[i]) == typeid(SemiLuxRoom) && Hotel[i]->isEmpty())
				{
					SemiLuxRoom* p = dynamic_cast<SemiLuxRoom*>(Hotel[i]);
					if (p != nullptr)
					{
						cout << *p << endl;
					}

				}
			}
		}
		else if (num == 9)
		{
			for (int i = 0; i < Hotel.size(); i++)
			{
				if (typeid(*Hotel[i]) == typeid(LuxRoom) && Hotel[i]->isEmpty())
				{
					LuxRoom* p = dynamic_cast<LuxRoom*>(Hotel[i]);
					if (p != nullptr)
					{
						cout << *p << endl;
					}
				}
			}
		}
		else
		{
			throw HotelException(to_string(num) + " does not meet the limits");
		}
	}
	else {
		throw HotelException("Hotel is empty");
	}
}

void Rooms::Hotels::sortRoom()
{
	if (!Hotel.empty())
	{
		int num;
		cout << "+--------------------------+\n";
		cout << "|   1 - Date               |\n";
		cout << "|   2 - Full Price         |\n";
		cout << "|   3 - Days               |\n";
		cout << "|   4 - Free               |\n";
		cout << "+--------------------------+\n";
		cout << "Num: ";
		cin >> num;
		if (num == 1)
		{
			sort(Hotel.begin(), Hotel.end(), [](Room* a, Room* b) {
				return a->getInhabited() < b->getInhabited();
				});
		}
		else if (num == 2)
		{
			sort(Hotel.begin(), Hotel.end(), [](Room* a, Room* b) {
				return a->getFullPrice() < b->getFullPrice();
				});
		}
		else if (num == 3)
		{
			sort(Hotel.begin(), Hotel.end(), [](Room* a, Room* b) {
				return a->getDays() < b->getDays();
				});
		}
		else if (num == 4)
		{
			sort(Hotel.begin(), Hotel.end(), [](Room* a, Room* b) {
				return a->getFree() < b->getFree();
				});
		}
		else
		{
			throw HotelException(to_string(num) + " does not meet the limits");
		}
	}
	else {
		throw HotelException("Hotel is empty");
	}
}

void Rooms::Hotels::printToFile()
{
	ofstream file("hotelRoom.txt");
	if (file.is_open())
	{
		file << "\n";
		for (int i = 0; i < Hotel.size(); i++)
		{
			if (Hotel[i]->isEmpty())
			{
				Hotel[i]->infoFile(file);
			}
		}
		file.close();
	}
	else {
		throw HotelException("Hotel not open");
	}
}

void Rooms::Hotels::showListHotel() const
{
	for (int i = 0; i < Hotel.size(); i++)
	{
		if (Hotel[i]->isEmpty())
		{
			Hotel[i]->showInfo();
			cout << "Full Price: " << Hotel[i]->getFullPrice() << endl << endl;
		}
	}
}