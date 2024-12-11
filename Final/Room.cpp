#include "Room.h"

Rooms::Room::Room()
{
    id = 0;
    num = 0;
    number = 0;
    inhabited = Date();
    days = 0;
    priceDay = 0.0;
}

Rooms::Room::Room(int id, int num, bool free, int number, Date inhabited, int days, double priceDay)
{
    this->id = id;
    this->num = num;
    this->free = free;
    this->number = number;
    this->inhabited = inhabited;
    this->days = days;
    this->priceDay = priceDay;
}

Rooms::Room::~Room()
{
}

long Rooms::Room::getId() const
{
    return id;
}

int Rooms::Room::getNum() const
{
    return num;
}

int Rooms::Room::getFree() const
{
    return free;
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

void Rooms::Room::setFree(bool free)
{
    this->free = free;
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
