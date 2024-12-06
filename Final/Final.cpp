#include <iostream>
#include <cmath>
#include "Room.h"
#include "StandardRoom.h"
using namespace std;

int main()
{
    srand(time(0));
    Rooms::StandardRoom a(1,101, 3, Date(2024, 11, 6), 11, 120, 1);
    a.showInfo();
    cout << a.getFullPrice() << endl;
}