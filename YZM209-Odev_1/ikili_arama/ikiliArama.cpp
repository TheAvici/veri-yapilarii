#include <iostream>
#include <vector>

bool ikiliArama(int arananDeger, const std::vector<int> A) {
    int sol = 0 ;
    int sag = A.size() - 1;

    while (sol <= sag) {
        int orta = (sol + sag) / 2;
        if (A[orta] == arananDeger) {
            std::cout << "Aradiginiz degerin dizi indisi = " << orta << std::endl;
            return true;
        }
        else if (A[orta] < arananDeger) {
            sol = orta + 1;
        }
        else {
            sag = orta - 1;
        }
    }
    std::cout << "Deger bulunamadi." << std::endl;
    return false;
}
int main () {
    std::vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    int aranan;
    std::cout << "Aramak istediginiz deger nedir ?" << std::endl;
    std::cin >> aranan;

    ikiliArama(aranan, A);

    return 0;
}