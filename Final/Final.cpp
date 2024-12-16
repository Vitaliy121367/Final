#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Room.h"
#include "StandardRoom.h"
#include "SemiLuxRoom.h"
#include "LuxRoom.h"
#include "Hotels.h"
#include <Windows.h>
using namespace std;

int main()
{
    int num;
    Rooms::Hotels R;
    while (true) 
    {
        num = 0;
        cout << "+----------------------------+\n";
        cout << "|    1 - Add Room            |\n";
        cout << "|    2 - Edit Room           |\n";
        cout << "|    3 - Buy Release Room    |\n";
        cout << "|    4 - Del Room            |\n";
        cout << "|    5 - Search Room         |\n";
        cout << "|    6 - Sort Room           |\n";
        cout << "|    7 - Show List Hotel     |\n";
        cout << "|    8 - Exit                |\n";
        cout << "+----------------------------+\n";
        cout << "Num: ";
        cin >> num;
        Sleep(300);
        if (num == 1)
        {
            while (true) 
            {
                num = 0;
                system("CLS");
                cout << "+----------------------------+\n";
                cout << "|    1 - Standard Room       |\n";
                cout << "|    2 - SemiLuxRoom         |\n";
                cout << "|    3 - LuxRoom             |\n";
                cout << "|    4 - Exit                |\n";
                cout << "+----------------------------+\n";
                cout << "Num: ";
                cin >> num;
                if (num == 1)
                {
                    Rooms::StandardRoom  standardRoom;
                    cin >> standardRoom;
                    try
                    {
                        R.addRoom(&standardRoom);
                        Sleep(500);
                    }
                    catch (const HotelException& obj)
                    {
                        cout << obj.showMessage(); 
                        Sleep(3000);
                    }
            Sleep(500);
                    system("CLS");
                    break;
                }
                else if (num == 2)
                {
                    Rooms::SemiLuxRoom  semiLuxRoom;
                    cin >> semiLuxRoom;
                    try
                    {
                        R.addRoom(&semiLuxRoom);
                        Sleep(500);
                    }
                    catch (const HotelException& obj)
                    {
                        cout << obj.showMessage(); 
                        Sleep(3000);
                    }
                    Sleep(500);
                    system("CLS");
                    break;
                }
                else if (num == 3)
                {
                    Rooms::LuxRoom  luxRoom;
                    cin >> luxRoom;
                    try
                    {
                        R.addRoom(&luxRoom);
                        Sleep(500);
                    }
                    catch (const HotelException& obj)
                    {
                        cout << obj.showMessage(); 
                        Sleep(3000);
                    }
                    Sleep(500);
                    system("CLS");
                    break;
                }
                else if (num == 4)
                {
                    Sleep(500);
                    system("CLS");
                    break;
                }
                else
                {
                    cout << "Error!!!\n";
                }
                Sleep(500);
            }
        }
        else if(num == 2)
        {
            num = 0;
            system("CLS");
            cout << "Enter id room: ";
            cin >> num;
            try
            {
                R.editRoom(num);
                Sleep(500);
            }
            catch (const HotelException& obj)
            {
                cout << obj.showMessage(); 
                Sleep(3000);
            }
            Sleep(500);
            system("CLS");
        }
        else if(num == 3)
        {
            num = 0;
            system("CLS");
            cout << "Enter id room: ";
            cin >> num;
            try
            {
                R.buyReleaseRoom(num);
                Sleep(500);
            }
            catch (const HotelException& obj)
            {
                cout << obj.showMessage(); 
                Sleep(3000);
            }
            Sleep(500);
            system("CLS");
        }
        else if (num == 4)
        {
            num = 0;
            system("CLS");
            cout << "Enter id room: ";
            cin >> num;
            try
            {
                R.delRoom(num);
                Sleep(500);
            }
            catch (const HotelException& obj)
            {
                cout << obj.showMessage();
                Sleep(3000);
            }
            Sleep(500);
            system("CLS");
        }
        else if (num == 5)
        {
            num = 0;
            system("CLS");
            R.searchRoom();
            Sleep(7000);
            system("CLS");
        }
        else if (num == 6)
        {
            num = 0;
            system("CLS");
            R.sortRoom();
            Sleep(2000);
            system("CLS");
        }
        else if (num == 7)
        {
            num = 0;
            system("CLS");
            R.showListHotel();
            cout << "\n\n";
        }
        else if (num == 8)
        {
            string save;
            cout << "Save to file: ";
            cin >> save;
            if (save == "Yes" || save == "yes" || save == "ok" || save == "Ok" || save == "True" || save == "1")
            {
                R.printToFile();
                cout << "File save";
                break;
            }
            else
            {
                cout << "File not save";
                break;
            }
        }
    }
}