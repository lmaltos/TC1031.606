#include <fstream>
#include "Registro.h"
#include <vector>
using namespace std;

int main() {
    ifstream file;
    string path = "Bitacora.txt";
    vector<Registro> bitacora;
    string month;
    int day;
    string hhmmss;
    string ip;
    string message;

    file.open(path);
    while (!file.eof()) {
        file >> month >> day >> hhmmss >> ip >> message;
        bitacora.push_back(Registro(month, day, hhmmss, ip, message));
    };
    file.close();
}