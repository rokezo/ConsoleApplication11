#include <iostream>
#include <numeric>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        return gcd(a, b);
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int den) : numerator(num), denominator(den) {
        reduce();
    }

    void input() {
        cout << "Введіть чисельник: ";
        cin >> numerator;
        cout << "Введіть знаменник: ";
        cin >> denominator;
        reduce();
    }

    void reduce() {
        int gcd_value = gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
    }

    Fraction operator+(const Fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator-(const Fraction& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator*(const Fraction& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator/(const Fraction& other) const {
        int new_num = numerator * other.denominator;
        int new_den = denominator * other.numerator;
        return Fraction(new_num, new_den);
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(3, 4);
    Fraction f2(5, 6);
    Fraction f3;

    f3 = f1 + f2;
    f3.print(); 

    f3 = f1 - f2;
    f3.print(); 

    f3 = f1 * f2;
    f3.print(); 

    f3 = f1 / f2;
    f3.print();

    return 0;
}