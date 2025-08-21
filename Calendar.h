#pragma once
#include <iostream>
using namespace std;
#include "MyDate.h"

class Calendar
{
private:
    static const int MAX_DATES = 30;
    MyDate* _dates[MAX_DATES];
	int _occupiedCount;

public:
    Calendar();
    Calendar(const Calendar& other); 
    void setOccupiedCount(int num) { this->_occupiedCount = num; }
    int getOccupiedCount() const { return this->_occupiedCount; }
    

    void setDate(int num, MyDate& date);
    bool isFree(int num) const; 
    int firstFree() const; 
    bool insert(MyDate& date); 
    int oldest() const; 
    int datesNum() const; 
    void deleteAll(); 
    void deleteDate(int num);
    void print() const; 
};

