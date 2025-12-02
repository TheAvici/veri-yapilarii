// main.cpp
#include "CircularLinkedList.h"

int main() {
    CircularLinkedList list;

    // Başa ekleme
    list.push_front(20); // 20
    list.push_front(10); // 10 -> 20 -> (geri donus head)
    list.printList();

    // Sona ekleme
    list.push_back(30);  // 10 -> 20 -> 30 -> ...
    list.push_back(40);  // 10 -> 20 -> 30 -> 40 -> ...
    list.printList();

    // Araya ekleme: 20'den sonra 25
    list.insert_after(20, 25); // 10 -> 20 -> 25 -> 30 -> 40 -> ...
    list.printList();

    // Baştan silme
    list.pop_front(); // 10 gider: 20 -> 25 -> 30 -> 40 -> ...
    list.printList();

    // Belirli değeri silme
    list.remove_value(30); // 30 gider: 20 -> 25 -> 40 -> ...
    list.printList();

    list.remove_value(100); // olmayan değer
    list.printList();

    // Program biterken ~CircularLinkedList() çağrılır ve tüm düğümler delete edilir.
    return 0;
}
