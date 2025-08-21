#include "MyDate.h"

MyDate::MyDate(int year, int month, int day)
{
	this->setDate(year, month, day);
}

MyDate::MyDate(MyDate& date)
{
	this->setYear(date.getYear());
	this->setMonth(date.getMonth());
	this->setDay(date.getDay());
}

MyDate::~MyDate() {
	if (this->_comment) {
		delete[] this->_comment;
		this->_comment = nullptr;
	}
}

void MyDate::setDay(int day)
{
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (day <= daysInMonth[this->getMonth()-1]) { this->_day = day; }
	else { this->_day = 1; }
}

void MyDate::setMonth(int month)
{
	if (month > 0 && month <= 12) { this->_month = month; }
	else { this->_month = 1; }
}

void MyDate::setYear(int year)
{
	if (year > 0) {this->_year = year;}
	else { this->_year = 1;}
}


void MyDate::setDate(int year, int month, int day)
{
	this->setYear(year);
	this->setMonth(month);
	this->setDay(day);
}

void MyDate::addComment(const char* comment)
{
	if (this->_comment) { delete[] this->_comment; }
	this->_comment = new char[strlen(comment) + 1];
	strcpy_s(this->_comment, strlen(comment) + 1, comment);
}

void MyDate::print() const {
	cout << (this->_day < 10 ? "0" : "") << this->_day << "/"
		<< (this->_month < 10 ? "0" : "") << this->_month << "/"
		<< this->_year;

	if (this->_comment) {cout << " - " << this->_comment;}
	cout << endl;
}


void MyDate::incDate() {
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	this->setDay(this->getDay() + 1);

	if (this->getDay() > daysInMonth[this->getMonth() - 1]) {
		this->setDay(1);
		this->setMonth(this->getMonth() + 1);

		if (this->getMonth() > 12) {
			this->setMonth(1);
			this->setYear(this->getYear() + 1);
		}
	}
}

void MyDate::init()
{
	this->setYear(2025);
	this->setMonth(1);
	this->setDay(1);
}

bool MyDate::isBefore(const MyDate& other) const {
	if (this->_year < other._year) return true;
	if (this->_year == other._year && this->_month < other._month) return true;
	if (this->_year == other._year && this->_month == other._month && this->_day < other._day) return true;
	return false;
}

void MyDate::changeComment(const char* newComment) {
	if (this->_comment) {delete[] this->_comment; }
	this->_comment = new char[strlen(newComment) + 1];
	strcpy_s(this->_comment, strlen(newComment) + 1, newComment);
}
