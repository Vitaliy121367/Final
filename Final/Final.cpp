#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
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
    a.seveToTextFile("hotelRoom.txt");
    Rooms::SemiLuxRoom b(2, 102, 0, 2, Date(2024, 12, 9), 5, 150, 0, 7.5, 1);
    cout << b;
    cout << "Full Price: " << b.getFullPrice() << endl << endl;
    b.seveToTextFile("hotelRoom.txt");
    Rooms::LuxRoom c(3, 103, 1, 3, Date(2024, 10, 1), 5, 200, 1, 6, 1, 100);
    cout << c;
    cout << "Full Price: " << c.getFullPrice() << endl << endl;
    c.seveToTextFile("hotelRoom.txt");*/

    Rooms::Hotels R;

    /*Rooms::StandardRoom a(101, 1, 3, Date(2024, 11, 6), 11, 120, 1);
    Rooms::SemiLuxRoom b(102, 0, 2, Date(2024, 12, 9), 5, 150, 0, 7.5, 1);
    Rooms::LuxRoom c(103, 1, 3, Date(2024, 10, 1), 5, 200, 1, 6, 1, 100);
    R.addRoom(&a);
    R.addRoom(&b);
    R.addRoom(&c);*/
    R.showListHotel();
    R.sortRoom();
    R.printToFile();
}