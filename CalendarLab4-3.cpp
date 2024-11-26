#include <iostream>
#include <iomanip>

using namespace std;


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int getDaysInMonth(int month, int year) {
    if (month == 2) {  
        if (isLeapYear(year)) {  
            return 29; 
        }
        else {
            return 28; 
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;  
    }
    return 31; 
}


int getFirstDayOfYear(int year) {
    int day = 0; 

    for (int i = 1900; i < year; ++i) {
        if (isLeapYear(i)) {
            day = (day + 366) % 7;  
        }
        else {
            day = (day + 365) % 7;  
        }
    }

    return day;  
}



void printCalendar(int year) {
    const string months[] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                              "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
    int startDay = getFirstDayOfYear(year);

    cout << "Календарь для " << year << endl;

    for (int month = 1; month <= 12; ++month) {
        cout << endl << months[month - 1] << endl;
        cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;

        int days = getDaysInMonth(month, year);

        for (int i = 0; i < startDay; ++i) {
            cout << "   ";
        }

        for (int day = 1; day <= days; ++day) {
            cout << setw(2) << day << " ";
            startDay = (startDay + 1) % 7;
            if (startDay == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int year;
    cout << "Введите год: ";
    cin >> year;

    printCalendar(year);

    return 0;
}
