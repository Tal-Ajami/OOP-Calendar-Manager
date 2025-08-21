#include <iostream>
#include "Calendar.h"

int main() {
    // Creating MyDate objects
    MyDate date1(2025, 5, 15);
    date1.addComment("Birthday Party");
    MyDate date2(2024, 12, 25);
    date2.addComment("Christmas");

    // Printing dates
    cout << "Date 1: ";
    date1.print();
    cout << "Date 2: ";
    date2.print();

    // Modifying a date
    date1.setDate(2025, 1, 1);
    cout << "Date 1 after change: ";
    date1.print();

    // Incrementing a date by one day
    date2.incDate();
    cout << "Date 2 after increment: ";
    date2.print();

    // Changing a comment
    date1.changeComment("New Year Celebration");
    cout << "Date 1 after comment change: ";
    date1.print();

    // Creating a calendar
    Calendar calendar;

    // Adding dates to the calendar
    calendar.insert(date1);
    calendar.insert(date2);

    // Printing the calendar
    cout << "\nCalendar:" << endl;
    calendar.print();

    // Finding the oldest date in the calendar
    int oldestIndex = calendar.oldest();
    cout << "\nOldest date is at slot: " << oldestIndex << endl;
    

    // Printing the number of dates in the calendar
    cout << "Number of dates in calendar: " << calendar.datesNum() << endl;

    // Deleting a specific date from the calendar
    cout << "Deleting date in slot 1:" << endl;
    calendar.deleteDate(1);
    cout << "\nCalendar:" << endl;
    calendar.print();

    // Deleting all dates from the calendar
    cout << "Deleting all dates:" << endl;
    calendar.deleteAll();
    cout << "\nCalendar:" << endl;
    calendar.print();

    return 0;
}
