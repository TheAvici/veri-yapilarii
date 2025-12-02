//
// Created by Sedo on 2.12.2025.
//

#ifndef DIKDORTGEN_DIKDORTGEN_H
#define DIKDORTGEN_DIKDORTGEN_H

class Dikdortgen {
private:
    double genislik;
    double yukseklik;

public:
    // Varsayılan ctor
    Dikdortgen();

    // Parametreli ctor
    Dikdortgen(double g, double y);

    double alanHesapla() const;
    double cevreHesapla() const;
    void bilgileriYazdir() const;

    // (İstersen getter/setter ekleyebilirsin)
};



#endif //DIKDORTGEN_DIKDORTGEN_H