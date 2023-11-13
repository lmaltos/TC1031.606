#ifndef ADYACENTE_H
#define ADYACENTE_H
#include <string>

class adyacente {
  private:
    std::string id;
    adyacente *next = nullptr;
  public:
    adyacente(std::string _id) {id = _id;}
    std::string Id() {return id;}
    adyacente* Next() {return next;}
    void setNext(adyacente* _next) {next = _next;}
};

#endif