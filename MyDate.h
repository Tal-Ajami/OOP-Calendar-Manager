#pragma once
#include <iostream>
using namespace std;

class MyDate
{
private:
	int _day;
	int _month;
	int _year;
	char* _comment;

public:
	MyDate(int year = 2020, int month = 1, int day = 1 );
	MyDate(MyDate& date);
	~MyDate();

	int getDay() const { return this->_day; }
	int getMonth() const { return this->_month; }
	int getYear() const { return this->_year; }

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int year, int month, int day);

	void addComment(const char* comment);
	void printComment() const { cout << this->_comment << endl; }

	void print() const;
	void incDate();
	void init();
	bool isBefore(const MyDate& other) const;
	void changeComment(const char* newComment);





};

