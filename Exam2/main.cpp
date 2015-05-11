#include <iostream>
#include "Triple.h"

using namespace std;

int main() {
    Triple<int,double, char> tt(1,3.3,'A');

    Triple<double, char, int> td(4.2, 'b', 4);
    tt.print();
    td.print();

    cout << td.getT1() << endl;
    td.setT1(5.2);
    cout << td.getT1() << endl;

    return 0;
}