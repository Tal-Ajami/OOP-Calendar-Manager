# Calendar & Date Management (C++ OOP Project)

This project implements a simple **Calendar and Date Management System** in C++ using **Object-Oriented Programming** principles.  
It demonstrates the use of **classes, dynamic memory allocation, copy constructors, and encapsulation**.  

---

- **MyDate class**  
  - Represents a date (day, month, year) with an optional personal note.  
  - Provides functions to display, modify, and validate dates.  
  - Includes **getters and setters** for safe and controlled access to internal fields.  

- **Calendar class**  
  - Manages a calendar of up to 30 dates.  
  - Supports **adding and removing** dates.  
  - Finds the **first available slot** in the calendar.  
  - Retrieves the **earliest date** among all stored dates.  
  - Prints a formatted list of all saved dates.  

- **Object-Oriented Programming (OOP) principles**  
  - Uses constructors, destructors, and **deep copy** to ensure safe memory management.  
  - Demonstrates **encapsulation**: private fields are only accessible through class methods.  

---

## Screenshots
Example output of the program:

![Calendar Screenshot](screenshot.png)

---

## Project Structure
- `main.cpp` – Runs demo operations on the calendar.  
- `MyDate.h / MyDate.cpp` – Defines and implements the **MyDate** class.  
- `Calendar.h / Calendar.cpp` – Defines and implements the **Calendar** class.  

---

## Example Usage
```cpp
int main() {
    Calendar calendar;
    MyDate date1(2023, 5, 10);
    MyDate date2(2021, 1, 1);

    calendar.insert(date1);
    calendar.insert(date2);

    cout << "Number of dates: " << calendar.datesNum() << endl;
    cout << "Oldest date is in slot: " << calendar.oldest() << endl;

    calendar.print();
    return 0;
}
