#include <iostream>
#include <queue>   // std::queue için
using namespace std;

// Öğretici olsun diye kendi isEmpty fonksiyonumuz
bool isEmpty(const queue<int>& q) {
    return q.empty();
}

// Kuyruğu yazdırmak için yardımcı fonksiyon
// NOT: std::queue da iterator vermez, o yüzden
// KOPYASINI alıp front/pop ile ilerliyoruz.
void printQueue(queue<int> q) { // pass by value: KOPYA
    cout << "Queue (bastan sona): ";
    if (q.empty()) {
        cout << "(bos)";
    } else {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    }
    cout << endl;
}

int main() {
    queue<int> q;  // int türünde kuyruk

    cout << "==============================\n";
    cout << "  std::queue OGRETICI ORNEK   \n";
    cout << "==============================\n\n";

    cout << "1) Yeni bir queue olusturduk.\n";
    cout << "   Baslangicta bos mu? q.empty() = "
         << (q.empty() ? "true" : "false") << endl;
    cout << "   isEmpty(q) = " << (isEmpty(q) ? "true" : "false") << endl;
    cout << "   size = " << q.size() << endl;
    printQueue(q);
    cout << "\n--------------------------------------------------\n";

    // PUSH örnekleri
    cout << "2) q.push(10) yapiyoruz.\n";
    q.push(10); // kuyruk: [10]
    cout << "   size = " << q.size() << endl;
    cout << "   front() = " << q.front() << "  back() = " << q.back() << endl;
    printQueue(q);
    cout << "--------------------------------------------------\n";

    cout << "3) q.push(20) yapiyoruz.\n";
    q.push(20); // kuyruk: [10, 20]
    cout << "   size = " << q.size() << endl;
    cout << "   front() = " << q.front() << "  back() = " << q.back() << endl;
    printQueue(q);
    cout << "--------------------------------------------------\n";

    cout << "4) q.push(30) yapiyoruz.\n";
    q.push(30); // kuyruk: [10, 20, 30]
    cout << "   size = " << q.size() << endl;
    cout << "   front() = " << q.front() << "  back() = " << q.back() << endl;
    printQueue(q);
    cout << "--------------------------------------------------\n";

    // POP örnegi
    cout << "5) q.pop() yapiyoruz (en BASTAKI elemani cikarir).\n";
    if (!q.empty()) {
        cout << "   Cikarilan (front) deger: " << q.front() << endl;
        q.pop(); // 10 gider, kuyruk: [20, 30]
    }
    cout << "   size = " << q.size() << endl;
    cout << "   front() = " << q.front()
         << "  back() = " << q.back() << endl;
    printQueue(q);
    cout << "--------------------------------------------------\n";

    cout << "6) q.pop() tekrar.\n";
    if (!q.empty()) {
        cout << "   Cikarilan (front) deger: " << q.front() << endl;
        q.pop(); // 20 gider, kuyruk: [30]
    }
    cout << "   size = " << q.size() << endl;
    cout << "   front() = " << q.front()
         << "  back() = " << q.back() << endl;
    printQueue(q);
    cout << "--------------------------------------------------\n";

    cout << "7) q.pop() tekrar.\n";
    if (!q.empty()) {
        cout << "   Cikarilan (front) deger: " << q.front() << endl;
        q.pop(); // 30 gider, kuyruk: []
    }
    cout << "   size = " << q.size() << endl;
    cout << "   empty() = " << (q.empty() ? "true" : "false") << endl;
    cout << "   isEmpty(q) = " << (isEmpty(q) ? "true" : "false") << endl;
    printQueue(q);
    cout << "--------------------------------------------------\n";

    cout << "8) Bos queue'da front/back/pop kullanmamak gerekir!\n";
    cout << "   once empty() ile bos mu diye kontrol etmelisin.\n\n";

    // Küçük interaktif menü
    int secim;
    do {
        cout << "\n=== MINI MENU (QUEUE) ===\n";
        cout << "1 - Push (sona ekle)\n";
        cout << "2 - Pop (bastan cikar)\n";
        cout << "3 - Front (bastaki eleman)\n";
        cout << "4 - Back (sondaki eleman)\n";
        cout << "5 - Size\n";
        cout << "6 - Empty / isEmpty\n";
        cout << "7 - Queue'yu yazdir\n";
        cout << "0 - Cikis\n";
        cout << "Secim: ";
        cin >> secim;

        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Gecersiz giris!\n";
            continue;
        }

        switch (secim) {
            case 1: {
                int deger;
                cout << "Eklenecek deger: ";
                cin >> deger;
                q.push(deger);
                cout << "push(" << deger << ") yapildi.\n";
                break;
            }
            case 2: {
                if (q.empty()) {
                    cout << "Queue bos, pop yapilamaz.\n";
                } else {
                    cout << "pop() -> cikan deger (front): " << q.front() << endl;
                    q.pop();
                }
                break;
            }
            case 3: {
                if (q.empty()) {
                    cout << "Queue bos, front yok.\n";
                } else {
                    cout << "front() = " << q.front() << endl;
                }
                break;
            }
            case 4: {
                if (q.empty()) {
                    cout << "Queue bos, back yok.\n";
                } else {
                    cout << "back() = " << q.back() << endl;
                }
                break;
            }
            case 5: {
                cout << "size() = " << q.size() << endl;
                break;
            }
            case 6: {
                cout << "empty() = " << (q.empty() ? "true" : "false") << endl;
                cout << "isEmpty(q) = " << (isEmpty(q) ? "true" : "false") << endl;
                break;
            }
            case 7: {
                printQueue(q);
                break;
            }
            case 0:
                cout << "Cikis yapiliyor...\n";
                break;
            default:
                cout << "Gecersiz secim.\n";
        }

    } while (secim != 0);

    return 0;
}
