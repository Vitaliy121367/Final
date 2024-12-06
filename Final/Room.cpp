#include "Room.h"

Rooms::Room::Room()
{
    identifier = rand() * pow(10, 10) + rand();
    num = 0;
    number = 0;
    inhabited = Date();
    days = 0;
    priceDay = 0.0;
}

Rooms::Room::Room(int num, int number, Date inhabited, int days, double priceDay)
{
    identifier = rand() * pow(10, 10) + rand();
    this->num = num;
    this->number = number;
    this->inhabited = inhabited;
    this->days = days;
    this->priceDay = priceDay;
}

Rooms::Room::~Room()
{
}

long Rooms::Room::getIdentifier() const
{
    return identifier;
}

int Rooms::Room::getNum() const
{
    return num;
}

int Rooms::Room::getNumber() const
{
    return number;
}

Date Rooms::Room::getInhabited() const
{
    return inhabited;
}

int Rooms::Room::getDays() const
{
    return days;
}

double Rooms::Room::getPriceDay() const
{
    return priceDay;
}

void Rooms::Room::setDays(int days)
{
    if (days>this->days)
    {
        this->days = days;
    }
}

void Rooms::Room::setPriceDay(double priceDay)
{
    this->priceDay = priceDay;
}
