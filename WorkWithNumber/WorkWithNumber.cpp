#include <iostream>
#include <cmath>
#include <cassert>
#include <gtest/gtest.h>
#define TEST_MODE

using namespace std;

class Number {
private:
    int value;

public:
    // Constructor to initialize the number
    Number(int n) : value(n) {}

    // Check if the number is prime
    bool isPrime() const {
        if (value < 2) return false;
        for (int i = 2; i <= sqrt(value); i++) {
            if (value % i == 0) return false;
        }
        return true;
    }

    // Calculate the sum of digits
    int sumOfDigits() const {
        int sum = 0;
        int n = value;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    // Check if the number is perfect
    bool isPerfectNumber() const {
        if (value < 1) return false;
        int sum = 0;
        for (int i = 1; i <= value / 2; i++) {
            if (value % i == 0) {
                sum += i;
            }
        }
        return sum == value;
    }

    // Calculate GCD with another number
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Get the number
    int getValue() const {
        return value;
    }
};

#ifdef TEST_MODE
// Unit tests

void testIsPrime() {
    Number n1(29);
    assert(n1.isPrime() == true); // 29 is prime

    Number n2(15);
    assert(n2.isPrime() == false); // 15 is not prime
}

void testSumOfDigits() {
    Number n1(1234);
    assert(n1.sumOfDigits() == 10); // 1+2+3+4 = 10

    Number n2(0);
    assert(n2.sumOfDigits() == 0); // Sum of digits of 0 is 0
}

void testIsPerfectNumber() {
    Number n1(28);
    assert(n1.isPerfectNumber() == true); // 28 is a perfect number

    Number n2(12);
    assert(n2.isPerfectNumber() == false); // 12 is not a perfect number
}

void testGcd() {
    assert(Number::gcd(56, 98) == 14); // GCD of 56 and 98 is 14
    assert(Number::gcd(101, 10) == 1); // GCD of 101 and 10 is 1
}

int main() {
    // Running tests
    testIsPrime();
    testSumOfDigits();
    testIsPerfectNumber();
    testGcd();

    cout << "All tests passed!" << endl;
    return 0;
}
#else
// Main program (without tests)

int main() {

    cout << "Not in Test Mode" << endl;

    int n1 = 29;

    Number number1(n1);
    if (number1.isPrime()) {
        cout << n1 << " is a prime number." << endl;
    }
    else {
        cout << n1 << " is not a prime number." << endl;
    }

    int n2 = 1234;
    Number number2(n2);
    cout << "The sum of the digits of " << n2 << " is: " << number2.sumOfDigits() << endl;

    int n3 = 28;
    Number number3(n3);
    if (number3.isPerfectNumber()) {
        cout << n3 << " is a perfect number." << endl;
    }
    else {
        cout << n3 << " is not a perfect number." << endl;
    }

    int a = 56, b = 98;
    cout << "The Greatest Common Divisor of " << a << " and " << b << " is: " << Number::gcd(a, b) << endl;

    return 0;
}
#endif
