#include <iostream>
#include <cmath>
#include "Room.h"
#include "StandardRoom.h"
#include "SemiLuxRoom.h"
#include "LuxRoom.h"
using namespace std;

int main()
{
    Rooms::StandardRoom a(1,101, 3, Date(2024, 11, 6), 11, 120, 1);
    a.showInfo();
    cout << a.getFullPrice() << endl << endl;
    Rooms::SemiLuxRoom b(2, 102, 2, Date(2024, 12, 9), 5, 150, 0, 7.5, 1);
    b.showInfo();
    cout << b.getFullPrice() << endl << endl;
    Rooms::LuxRoom c(3, 103, 3, Date(2024, 10, 1), 5, 200, 1, 6, 1, 100);
    c.showInfo();
    cout << c.getFullPrice() << endl << endl;
}