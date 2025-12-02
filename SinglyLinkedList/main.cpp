#include "LinkedList.h"

int main() {
    LinkedList list;

    // Başa ekleme
    list.push_front(20); // Liste: 20
    list.push_front(10); // Liste: 10 -> 20
    list.printList();

    // Sona ekleme
    list.push_back(30);  // Liste: 10 -> 20 -> 30
    list.push_back(40);  // Liste: 10 -> 20 -> 30 -> 40
    list.printList();

    // Araya ekleme: 20'den sonra 25 ekle
    list.insert_after(20, 25); // 10 -> 20 -> 25 -> 30 -> 40
    list.printList();

    // Baştan silme
    list.pop_front(); // 10 silinir: 20 -> 25 -> 30 -> 40
    list.printList();

    // Belirli bir değeri silme
    list.remove_value(30); // 30 silinir: 20 -> 25 -> 40
    list.printList();

    list.remove_value(100); // olmayan değer
    list.printList();

    // Program biterken ~LinkedList() çağrılır ve tüm düğümler delete edilir.
    return 0;
}
