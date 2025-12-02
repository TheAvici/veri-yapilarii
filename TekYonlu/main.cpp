#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

int main() {
    SinglyLinkedList list;

    list.push_front(30);
    list.push_back(40);
    list.push_front(20);

    cout << "Baslangic (20, 30, 40): ";
    list.printList();

    // 30'dan sonra 35 ekle
    Node* node_30 = list.getHead();
    while (node_30 != nullptr && node_30->data != 30) {
        node_30 = node_30->next;
    }

    if (node_30 != nullptr) {
        cout << "30'dan sonra 35 ekleniyor..." << endl;
        list.insert_after(node_30, 35);
        list.printList();
    }

    // Kuyruktan (tail) sonra 50 ekle
    cout << "Kuyruktan sonra 50 ekleniyor..." << endl;
    list.insert_after(list.getTail(), 50);
    list.printList();

    // Ortadan 35 sil
    cout << "Ortadaki 35 siliniyor..." << endl;
    list.deleteNode(35);
    list.printList();

    // Baştan 20 sil
    cout << "Bastan 20 siliniyor..." << endl;
    list.deleteNode(20);
    list.printList();

    // Sondan 50 sil
    cout << "Sondan 50 siliniyor..." << endl;
    list.deleteNode(50);
    list.printList();

    // Olmayan 100'ü silmeyi dene
    cout << "Olmayan 100 silinmeye calisiliyor..." << endl;
    list.deleteNode(100);
    list.printList();

    // Kalan elemanlari sil
    cout << "Kalan elemanlar siliniyor..." << endl;
    list.deleteNode(30);
    list.deleteNode(40);
    list.printList();

    // Destructor otomatik olarak tum node'lari delete edecek
    return 0;
}
