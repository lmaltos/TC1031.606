#ifndef REGISTRO_H
#define REGISTRO_H
#include "Date.h"

class Registro {
  private:
    Date date;
    string ip;
    string message;
  public:
    Registro();
    Registro(string,int,string,string,string);
    Date getDate() {return date;}
    bool operator>(const Registro &reg) {return date > reg.date;}
};

#endif