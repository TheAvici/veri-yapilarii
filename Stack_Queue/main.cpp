#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main() {
    std::cout << "=== STACK TEST ===\n";
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "Top: " << s.top() << "\n";
    s.pop();
    std::cout << "Top: " << s.top() << "\n";

    std::cout << "\n=== QUEUE TEST ===\n";
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    while (!q.empty()) {
        std::cout << "Front: " << q.front() << "\n";
        q.dequeue();
    }

    return 0;
}
