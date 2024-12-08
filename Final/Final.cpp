#include <iostream>
#include <cmath>
#include "Room.h"
#include "StandardRoom.h"
#include "SemiLuxRoom.h"
using namespace std;

int main()
{
    srand(time(0));
    Rooms::StandardRoom a(1,101, 3, Date(2024, 11, 6), 11, 120, 1);
    a.showInfo();
    cout << a.getFullPrice() << endl << endl;
    Rooms::SemiLuxRoom b(2, 102, 2, Date(2024, 12, 9), 5, 150, 0, 7.5, 1);
    b.showInfo();
    cout << b.getFullPrice() << endl << endl;
}