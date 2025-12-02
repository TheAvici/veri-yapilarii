#include "Dikdortgen.h"
#include <iostream>
using namespace std;

Dikdortgen::Dikdortgen()
    : genislik(1.0), yukseklik(1.0) // varsayılan 1x1
{
}

Dikdortgen::Dikdortgen(double g, double y)
    : genislik(g), yukseklik(y)
{
}

double Dikdortgen::alanHesapla() const {
    return genislik * yukseklik;
}

double Dikdortgen::cevreHesapla() const {
    return 2 * (genislik + yukseklik);
}

void Dikdortgen::bilgileriYazdir() const {
    cout << "Genislik: " << genislik
         << ", Yukseklik: " << yukseklik
         << ", Alan: " << alanHesapla()
         << ", Cevre: " << cevreHesapla()
         << endl;
}
