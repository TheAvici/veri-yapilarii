#include <iostream>
using namespace std;

void swapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    cout << "swapByValue fonksiyonu icinde: x = "
         << x << ", y = " << y << endl;
}

void swapByReference(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void swapByPointer(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 10;
    int b = 20;

    cout << "Baslangic degerleri: a = " << a << ", b = " << b << endl;

    cout << "\n1) swapByValue(a, b) cagriliyor..." << endl;
    swapByValue(a, b);
    cout << "swapByValue sonrasi: a = " << a << ", b = " << b << endl;

    cout << "\n2) swapByReference(a, b) cagriliyor..." << endl;
    swapByReference(a, b);
    cout << "swapByReference sonrasi: a = " << a << ", b = " << b << endl;

    cout << "\n3) swapByPointer(&a, &b) cagriliyor..." << endl;
    swapByPointer(&a, &b);
    cout << "swapByPointer sonrasi: a = " << a << ", b = " << b << endl;

    return 0;
}
