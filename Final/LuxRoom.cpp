#include "LuxRoom.h"

Rooms::LuxRoom::LuxRoom()
{
    wifiSpeed = 0;
}

Rooms::LuxRoom::LuxRoom(int num, bool free, int number, Date inhabited, int days, double priceDay, bool exitToSea, double sqBalcony, bool miniBar, double wifiSpeed):SemiLuxRoom(num, free, number, inhabited, days, priceDay, exitToSea, sqBalcony, miniBar)
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

bool Rooms::LuxRoom::isEmpty() const
{
    return id != 0 && num != 0 && number != 0 && days != 0 && priceDay != 0;
}

void Rooms::LuxRoom::infoFile(ofstream& file)const
{
    file << "LuxRoom" << endl;
    file << num << endl;
    file << free << endl;
    file << number << endl;
    file << inhabited.getDay() << " " << inhabited.getMonth() << " " << inhabited.getYear() << " " << endl;
    file << days << endl;
    file << priceDay << endl;
    file << exitToSea << endl;
    file << sqBalcony << endl;
    file << miniBar << endl;
    file << wifiSpeed << endl << endl;
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

void Rooms::LuxRoom::showInfo() const
{
    cout << "\tLuxRoom" << endl;
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
    cout << "Wi-Fi Speed: " << wifiSpeed << " mbps/s\n";
    cout << "Free: " << (free ? "Yes" : "No") << endl;
}

ostream& Rooms::operator<<(ostream& os, const LuxRoom& r)
{
    os << "\tLuxRoom" << endl
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
        << "Wi-Fi Speed: " << r.wifiSpeed << " mbps/s\n"
        << "Free: " << (r.free ? "Yes" : "No") << endl;
    return os;
}

istream& Rooms::operator>>(istream& is, LuxRoom& r)
{
    cout << "\tStandardRoom" << endl
        << "Id: " << r.id << endl
        << "Num: " << r.num << endl
        << "Free: " << r.free << endl
        << "Number: " << r.number << endl
        << "Inhabited: " << r.inhabited << endl
        << "Days: " << r.days << endl
        << "Price day: " << r.priceDay << endl
        << "Exit To Sea: " << r.exitToSea << endl
        << "Square Balcony: " << r.sqBalcony << " m^2" << endl
        << "Mini Bar: " << r.miniBar << endl
        << "Wifi Speed: " << r.wifiSpeed << endl << endl;
    is >> r.num >> r.free >> r.number >> r.inhabited >> r.days >> r.priceDay >> r.exitToSea >> r.sqBalcony >> r.miniBar >> r.wifiSpeed;
    return is;
}
