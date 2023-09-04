#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date {
  private:
    string month; // mes en str Aug, Sep, Oct,...
    int month_i; // mes en int 1,2,3,...
    int day;
    int hour;
    int minute;
    int second;
  public:
    bool operator>(const Date &) const;
    void calcMonth();
};

#endif