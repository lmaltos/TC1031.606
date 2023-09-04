#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void fillVector(vector<int> &, int);

int main() {
    srand(time(0)); // semilla para rand
    int n = 100;
    vector<int> myVect;
    fillVector(myVect, n);
    int index1, index2;
    index1 = rand() % n;
    index2 = rand() % n;

    cout << "myVect["<< index1 <<"] = " << myVect[index1] << endl;
    cout << "myVect["<< index2 <<"] = " << myVect[index2] << endl;
    int aux = myVect[index2];
    myVect[index2] = myVect[index1];
    myVect[index1] = aux;
    cout << "myVect["<< index1 <<"] = " << myVect[index1] << endl;
    cout << "myVect["<< index2 <<"] = " << myVect[index2] << endl;
}

void fillVector(vector<int> &vect, int n) {
    for (;n > 0;n--) {
        vect.push_back(rand());
    }
}
