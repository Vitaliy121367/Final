#pragma once
#include <iostream>
#include <string>
using namespace std;

class RoomException
{
public:
protected:
	string text;
public:
	RoomException() { text = "undefined exeption"; }
	RoomException(string text) { this->text = text; }
	virtual ~RoomException() {}

	virtual string showMessage()const = 0;
};

class HotelException : public RoomException {
public:
	HotelException(string text) :RoomException(text) {}
	string showMessage()const override {
		return "HotelException: " + text + ".\n";
	}
};