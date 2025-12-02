#include <iostream>
#include "Dikdortgen.h"
using namespace std;

int main() {
    cout << "d1 nesnesi (varsayilan):" << endl;
    Dikdortgen d1;
    d1.bilgileriYazdir();

    cout << "\nd2 nesnesi (parametreli):" << endl;
    Dikdortgen d2(12.5, 4.0);
    d2.bilgileriYazdir();

    cout << "\nAyrica d2 nesnesinin alan ve cevresi:" << endl;
    cout << "Alan: " << d2.alanHesapla() << endl;
    cout << "Cevre: " << d2.cevreHesapla() << endl;

    return 0;
}
