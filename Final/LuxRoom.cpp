#include "LuxRoom.h"

Rooms::LuxRoom::LuxRoom()
{
    wifiSpeed = 0;
}

Rooms::LuxRoom::LuxRoom(int id, int num, int number, Date inhabited, int days, double priceDay, bool exitToSea, double sqBalcony, bool miniBar, double wifiSpeed):SemiLuxRoom(id, num, number, inhabited, days, priceDay, exitToSea, sqBalcony, miniBar)
{
    this->wifiSpeed = wifiSpeed;
}

double Rooms::LuxRoom::getWifiSpeed() const
{
    return wifiSpeed;
}

void Rooms::LuxRoom::setWifiSpeed(double wifiSpeed)
{
    this->wifiSpeed = wifiSpeed;
}

void Rooms::LuxRoom::showInfo() const
{
    SemiLuxRoom::showInfo();
    cout << "Wi-Fi Speed: " << wifiSpeed << " mbps/s\n";
}

double Rooms::LuxRoom::getFullPrice() const
{
    double fullPrice = 0;
    fullPrice = priceDay * days * 2;
    if (days > 10)
    {
        fullPrice = fullPrice * 0.75;
    }
    if (this->getExitToSea() == 1)
    {
        fullPrice += fullPrice * 0.25;
    }
    if (sqBalcony == 1)
    {
        fullPrice += fullPrice * 0.15;
    }
    if (sqBalcony > 5)
    {
        fullPrice += fullPrice * 0.25;
    }
    if (sqBalcony > 7)
    {
        fullPrice += fullPrice * 0.40;
    }
    if (wifiSpeed>100)
    {
        fullPrice += fullPrice * 0.1;
    }
    return fullPrice;
}
