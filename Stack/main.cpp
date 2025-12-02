#include <iostream>
#include <stack>   // std::stack için
using namespace std;

// Sırf öğretmek için kendi isEmpty fonksiyonumuz.
// Aslında stack.empty() ile aynı işi yapıyor.
bool isEmpty(const stack<int>& s) {
    return s.empty();
}

// Stack'i ekrana yazdırmak için yardımcı fonksiyon
// Dikkat: std::stack iterator desteklemez, o yüzden
// KOPYASINI alıp pop pop ilerleyerek yazdırıyoruz.
void printStack(stack<int> s) { // kopya alıyoruz (pass by value)
    cout << "Stack (ustten alta): ";
    if (s.empty()) {
        cout << "(bos)";
    } else {
        while (!s.empty()) {
            cout << s.top() << " "; // en ustteki eleman
            s.pop();                // cikar, bir alta gec
        }
    }
    cout << endl;
}

int main() {
    stack<int> s;  // int türünde bir stack

    cout << "==============================\n";
    cout << "  std::stack OGRETICI ORNEK   \n";
    cout << "==============================\n\n";

    cout << "1) Yeni bir stack olusturduk.\n";
    cout << "   Baslangicta bos mu? s.empty() = "
         << (s.empty() ? "true" : "false") << endl;
    cout << "   isEmpty(s) = " << (isEmpty(s) ? "true" : "false") << endl;
    cout << "   size = " << s.size() << endl;
    printStack(s);
    cout << "\n--------------------------------------------------\n";

    // PUSH örnekleri
    cout << "2) s.push(10) yapiyoruz.\n";
    s.push(10); // en ust: 10
    cout << "   size = " << s.size() << endl;
    cout << "   top() = " << s.top() << endl;
    printStack(s);
    cout << "--------------------------------------------------\n";

    cout << "3) s.push(20) yapiyoruz.\n";
    s.push(20); // en ust: 20, altinda 10
    cout << "   size = " << s.size() << endl;
    cout << "   top() = " << s.top() << endl;
    printStack(s);
    cout << "--------------------------------------------------\n";

    cout << "4) s.push(30) yapiyoruz.\n";
    s.push(30); // en ust: 30, sonra 20, sonra 10
    cout << "   size = " << s.size() << endl;
    cout << "   top() = " << s.top() << endl;
    printStack(s);
    cout << "--------------------------------------------------\n";

    // POP örneği
    cout << "5) s.pop() yapiyoruz (en ustteki elemani cikarir).\n";
    if (!s.empty()) {
        cout << "   Cikarilan (top) deger: " << s.top() << endl;
        s.pop(); // 30 gider, ustte 20 kalir
    }
    cout << "   size = " << s.size() << endl;
    cout << "   top() = " << s.top() << endl;
    printStack(s);
    cout << "--------------------------------------------------\n";

    cout << "6) s.pop() tekrar.\n";
    if (!s.empty()) {
        cout << "   Cikarilan (top) deger: " << s.top() << endl;
        s.pop(); // 20 gider, ustte 10 kalir
    }
    cout << "   size = " << s.size() << endl;
    cout << "   top() = " << s.top() << endl;
    printStack(s);
    cout << "--------------------------------------------------\n";

    cout << "7) s.pop() tekrar.\n";
    if (!s.empty()) {
        cout << "   Cikarilan (top) deger: " << s.top() << endl;
        s.pop(); // 10 gider, stack bos
    }
    cout << "   size = " << s.size() << endl;
    cout << "   empty() = " << (s.empty() ? "true" : "false") << endl;
    cout << "   isEmpty(s) = " << (isEmpty(s) ? "true" : "false") << endl;
    printStack(s);
    cout << "--------------------------------------------------\n";

    cout << "8) Bos stack'te top/pop kullanmamak gerekir!\n";
    cout << "   once empty() ile bos mu diye kontrol etmelisin.\n\n";

    // Küçük bir interaktif kısım da ekleyelim (isteğe bağlı)
    int secim;
    do {
        cout << "\n=== MINI MENU ===\n";
        cout << "1 - Push\n";
        cout << "2 - Pop\n";
        cout << "3 - Top\n";
        cout << "4 - Size\n";
        cout << "5 - Empty / isEmpty\n";
        cout << "6 - Stack'i yazdir\n";
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
                s.push(deger);
                cout << "push(" << deger << ") yapildi.\n";
                break;
            }
            case 2: {
                if (s.empty()) {
                    cout << "Stack bos, pop yapilamaz.\n";
                } else {
                    cout << "pop() -> cikan deger: " << s.top() << endl;
                    s.pop();
                }
                break;
            }
            case 3: {
                if (s.empty()) {
                    cout << "Stack bos, top yok.\n";
                } else {
                    cout << "top() = " << s.top() << endl;
                }
                break;
            }
            case 4: {
                cout << "size() = " << s.size() << endl;
                break;
            }
            case 5: {
                cout << "empty() = " << (s.empty() ? "true" : "false") << endl;
                cout << "isEmpty(s) = " << (isEmpty(s) ? "true" : "false") << endl;
                break;
            }
            case 6: {
                printStack(s);
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
