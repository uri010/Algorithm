#include <iostream>

using namespace std;

class Equation {
private :
    int a;
    int b;
public :
    Equation(int a, int b) {
        this->a = a;
        this->b = b;
    }

    int getA() {
        return this->a;
    }

    int getB() {
        return this->b;
    }

    Equation &operator+(Equation &e) {
        int a, b;
        a = this->a + e.getA();
        b = this->b + e.getB();
        Equation R(a, b);
        return R;
    }

    Equation &operator-(Equation &e) {
        Equation R(this->a - e.getA(), this->b - e.getB());
        return R;
    }

    friend std::ostream &operator<<(std::ostream &, Equation &);
};

std::ostream &operator<<(std::ostream &out, Equation &e) {
    if (e.b > 0) {
        out << e.a << "x+" << e.b;
    } else if ((e.a == 0) && (e.b == 0)) {
        out << 0;
    } else {
        out << e.a << "x" << e.b;
    }
    return out;
}

int x, y;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> x >> y;
    Equation e1(x, y);
    cin >> x >> y;
    Equation e2(x, y);
    Equation result = e1 + e2;
    cout << result << "\n";
    result = e1 - e2;
    cout << result << "\n";
}