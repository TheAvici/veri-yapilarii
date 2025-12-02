//
// Created by Sedo on 2.12.2025.
//

#ifndef STACK_QUEUE_STACK_H
#define STACK_QUEUE_STACK_H

class Stack {
private:
    int* data;
    int capacity;
    int topIndex;

    void resize();

public:
    Stack();
    ~Stack();

    void push(int value);
    void pop();
    int top() const;
    bool empty() const;
    int size() const;
};




#endif //STACK_QUEUE_STACK_H