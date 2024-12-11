#include <iostream>
#include <cmath>
#include "Room.h"
#include "StandardRoom.h"
#include "SemiLuxRoom.h"
#include "LuxRoom.h"
#include "Hotels.h"
using namespace std;

int main()
{
    /*Rooms::StandardRoom a(1,101, 1, 3, Date(2024, 11, 6), 11, 120, 1);
    cout << a;
    cout <<"Full Price: " << a.getFullPrice() << endl << endl;
    Rooms::SemiLuxRoom b(2, 102, 0, 2, Date(2024, 12, 9), 5, 150, 0, 7.5, 1);
    cout << b;
    cout << "Full Price: " << b.getFullPrice() << endl << endl;
    Rooms::LuxRoom c(3, 103, 1, 3, Date(2024, 10, 1), 5, 200, 1, 6, 1, 100);
    cout << c;
    cout << "Full Price: " << c.getFullPrice() << endl << endl;*/

    Rooms::Hotels a;
    a.showListHotel();
    //ишак сделай перегрузку оператора >>
}