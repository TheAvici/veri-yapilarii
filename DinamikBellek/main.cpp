#include <iostream>
#include <random>
using namespace std;

int main() {
    int n;
    cout << "Dizi boyutunu girin (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Lutfen pozitif bir tamsayi girin." << endl;
        return 0;
    }

    int* dizi = nullptr;

    try {
        dizi = new int[n]; // dinamik bellek ayirma
    } catch (const bad_alloc& e) {
        cout << "Bellek ayirma basarisiz oldu: " << e.what() << endl;
        return 0;
    }

    // Rastgele sayilar icin
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 99);

    cout << "\nDizi elemanlari (rastgele sayilar):" << endl;
    for (int i = 0; i < n; ++i) {
        dizi[i] = dist(gen);
        cout << dizi[i] << " ";
    }
    cout << endl;

    // Bellek iadesi
    delete[] dizi;
    dizi = nullptr;

    cout << "\nBellek delete[] ile sisteme iade edildi." << endl;
    cout << "Artik dizi pointer'i nullptr yapildi; kullanmaya calismamaliyiz." << endl;

    return 0;
}
