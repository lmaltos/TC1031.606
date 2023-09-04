#include "Date.h"

bool Date::operator>(const Date &b) const{
    if (this->month != b.month) {
        return month_i > b.month_i;
    }
    else if (this->day != b.day) {
        return this->day > b.day;
    }
    else if (this->hour != b.hour) {
        return this->hour > b.hour;
    }
    // ... etc...
    return false;
}

void Date::calcMonth() {
    if (month == "Jan") {
        month_i = 1;
    } else if (month == "Feb") {
        month_i = 2;
    }
    // etc...
}