#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    list.printForward();
    list.printBackward();

    list.remove(10);
    list.printForward();

    return 0;
}
