#include "SemiLuxRoom.h"

Rooms::SemiLuxRoom::SemiLuxRoom()
{
    miniBar = 0;
    sqBalcony = 0;
}

Rooms::SemiLuxRoom::SemiLuxRoom(int id, int num, int number, Date inhabited, int days, double priceDay, bool exitToSea, double sqBalcony, bool miniBar):StandardRoom(id, num, number, inhabited, days, priceDay, exitToSea)
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

void Rooms::SemiLuxRoom::showInfo() const
{
    Rooms::StandardRoom::showInfo();
    if (sqBalcony==0)
    {
        cout << "Square Balcony: no balcony" << endl;
    }
    else 
    {
        cout << "Square Balcony: " << sqBalcony << " m^2" << endl;
    }
    cout << "Mini Bar: " << (miniBar ? "Yes" : "No") << endl;
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
