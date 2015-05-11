#include <iostream>
using namespace std;


class Integer {

public:

    explicit Integer(int x = 0)
        :i(x) {}

    Integer(const Integer &n) {
        i = n.i;
    }
    const Integer &operator=(const Integer &n) {
        i = n.i;
    }

    Integer operator+=(const Integer &n) {

        if(this != &n) {
            i = i + n.i;
        }
        return *this;
    }

    ~Integer() {
        delete i;
    }

    int getI() const {
        return i;
    }
private:
    int i;
};

ostream &operator<<(ostream &out, const Integer &n) {

    cout << "Value: " << n.i;

}