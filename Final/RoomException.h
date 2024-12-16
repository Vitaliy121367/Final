#pragma once
#include <iostream>
#include <string>

class RoomException {
protected:
    std::string text;
public:
    RoomException() : text("undefined exception") {}
    RoomException(std::string text) : text(text) {}
    virtual ~RoomException() {}

    virtual std::string showMessage() const = 0;
};

class HotelException : public RoomException {
public:
    HotelException(std::string text) : RoomException(text) {}
    std::string showMessage() const override {
        return "HotelException: " + text + ".\n";
    }
};
