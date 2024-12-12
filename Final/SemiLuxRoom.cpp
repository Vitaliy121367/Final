#include "SemiLuxRoom.h"

Rooms::SemiLuxRoom::SemiLuxRoom()
{
    miniBar = 0;
    sqBalcony = 0;
}

Rooms::SemiLuxRoom::SemiLuxRoom(int id, int num, bool free, int number, Date inhabited, int days, double priceDay, bool exitToSea, double sqBalcony, bool miniBar):StandardRoom(id, num, free, number, inhabited, days, priceDay, exitToSea)
{
    this->sqBalcony = sqBalcony;
    this->miniBar = miniBar;
}

double Rooms::SemiLuxRoom::getSqBalcony() const
{
    return sqBalcony;
}

bool Rooms::SemiLuxRoom::getMiniBar() const
{
    return miniBar;
}

void Rooms::SemiLuxRoom::setSqBalcony(double sqBalcony)
{
    if (sqBalcony>=0)
    {
        this->sqBalcony = sqBalcony;
    }
}

bool Rooms::SemiLuxRoom::isEmpty() const
{
    return id != 0 && num != 0 && number != 0 && days != 0 && priceDay != 0;
}

void Rooms::SemiLuxRoom::infoFile(ofstream& file)const
{
    file << "SemiLuxRoom" << endl;
    file << id << endl;
    file << num << endl;
    file << free << endl;
    file << number << endl;
    file << inhabited.getDay() << " " << inhabited.getMonth() << " " << inhabited.getYear() << " " << endl;
    file << days << endl;
    file << priceDay << endl;
    file << exitToSea << endl;
    file << sqBalcony << endl;
    file << miniBar << endl << endl;
}

double Rooms::SemiLuxRoom::getFullPrice() const
{
    double fullPrice = 0;
    fullPrice = priceDay * days * 1.5;
    if (days > 10)
    {
        fullPrice = fullPrice * 0.75;
    }
    if (this->getExitToSea() == 1)
    {
        fullPrice += fullPrice * 0.25;
    }
    if (sqBalcony>5)
    {
        fullPrice += fullPrice * 0.25;
    }
    if (sqBalcony > 7)
    {
        fullPrice += fullPrice * 0.40;
    }
    if (miniBar==1)
    {
        fullPrice += fullPrice * 0.15;
    }
    return fullPrice;
}

void Rooms::SemiLuxRoom::showInfo() const
{
    cout << "\tSemiLuxRoom" << endl;
    cout << "Id: " << id << endl;
    cout << "Num: " << num << endl;
    cout << "Number: " << number << endl;
    cout << "Inhabited: " << inhabited << endl;
    cout << "Evicted: " << inhabited + days << endl;
    cout << "Days: " << days << endl;
    cout << "Price day: " << priceDay << endl;
    cout << "Exit To Sea: " << (getExitToSea() ? "Yes" : "No") << endl;
    cout << "Square Balcony: " << sqBalcony << " m^2" << endl;
    cout << "Mini Bar: " << (miniBar ? "Yes" : "No") << endl;
    cout << "Free: " << (free ? "Yes" : "No") << endl;
}

ostream& Rooms::operator<<(ostream& os, const SemiLuxRoom& r)
{
    os << "\tSemiLuxRoom" << endl
        << "Id: " << r.id << endl
        << "Num: " << r.num << endl
        << "Number: " << r.number << endl
        << "Inhabited: " << r.inhabited << endl
        << "Evicted: " << r.inhabited + r.days << endl
        << "Days: " << r.days << endl
        << "Price day: " << r.priceDay << endl
        << "Exit To Sea: " << (r.getExitToSea() ? "Yes" : "No") << endl
        << "Square Balcony: " << r.sqBalcony << " m^2" << endl
        << "Mini Bar: " << (r.miniBar ? "Yes" : "No") << endl
        << "Free: " << (r.free ? "Yes" : "No") << endl;
    return os;
}
