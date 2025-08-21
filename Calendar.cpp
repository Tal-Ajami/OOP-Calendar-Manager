#include "Calendar.h"

Calendar::Calendar() {
    this->setOccupiedCount(0);
    for (int i = 0; i < MAX_DATES; ++i) {
        this->_dates[i] = nullptr;
    }
}

Calendar::Calendar(const Calendar& other){
    this->setOccupiedCount(other._occupiedCount);
    for (int i = 0; i < MAX_DATES; ++i) {
        if (other._dates[i] != nullptr) {
            this->_dates[i] = new MyDate(*other._dates[i]);
        }
        else {
            this->_dates[i] = nullptr;
        }
    }
}


void Calendar::setDate(int num, MyDate& date) {
    if (num < 1 || num > MAX_DATES) {
        cerr << "Invalid index" << endl; //check
        return;
    }
    int index = num - 1;
    if (this->_dates[index] != nullptr) {
        delete this->_dates[index];
        this->setOccupiedCount(this->getOccupiedCount() - 1);
    }
    this->_dates[index] = new MyDate(date);
    this->setOccupiedCount(this->getOccupiedCount() + 1);
}

bool Calendar::isFree(int num) const {
    if (num < 1 || num > MAX_DATES) {
        cerr << "Invalid index" << endl;
        return false;
    }
    return this->_dates[num - 1] == nullptr;
}

int Calendar::firstFree() const {
    for (int i = 0; i < MAX_DATES; ++i) {
        if (this->_dates[i] == nullptr) {
            return i + 1;
        }
    }
    return -1;
}

bool Calendar::insert(MyDate& date) {
    int freeIndex = this->firstFree();
    if (freeIndex == -1) {return false;}
    this->setDate(freeIndex, date);
    return true;
}

int Calendar::oldest() const {
    int oldestIndex = -1;
    MyDate* oldestDate = nullptr;
    for (int i = 0; i < MAX_DATES; ++i) {
        if (this->_dates[i] != nullptr && (oldestDate == nullptr || this->_dates[i]->isBefore(*oldestDate))) {
            oldestDate = this->_dates[i];
            oldestIndex = i + 1;
        }
    }
    return oldestIndex;
}

int Calendar::datesNum() const {
    return this->getOccupiedCount();
}

void Calendar::deleteAll() {
    for (int i = 0; i < MAX_DATES; ++i) {
        if (this->_dates[i] != nullptr) {
            delete this->_dates[i];
            this->_dates[i] = nullptr;
        }
    }
    this->setOccupiedCount(0);
}

void Calendar::deleteDate(int num) {
    if (num < 1 || num > MAX_DATES) {
        cerr << "Invalid index" << endl;
        return;
    }
    int index = num - 1;
    if (this->_dates[index] != nullptr) {
        delete this->_dates[index];
        this->_dates[index] = nullptr;
        this->setOccupiedCount(this->getOccupiedCount() - 1);
    }
}

void Calendar::print() const {
    bool isEmpty = true;
    for (int i = 0; i < MAX_DATES; ++i) {
        if (this->_dates[i] != nullptr) {
            isEmpty = false;
            cout << "Slot " << i + 1 << ": ";
            this->_dates[i]->print();
        }
    }
    if (isEmpty) {
        cout << "Empty Calendar" << endl;
    }
}
