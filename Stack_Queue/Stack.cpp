#include "Stack.h"
#include <stdexcept>

Stack::Stack() : capacity(4), topIndex(-1) {
    data = new int[capacity];
}

Stack::~Stack() {
    delete[] data;
}

void Stack::resize() {
    int newCap = capacity * 2;
    int* newData = new int[newCap];
    for (int i = 0; i <= topIndex; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCap;
}

void Stack::push(int value) {
    if (topIndex + 1 == capacity) {
        resize();
    }
    data[++topIndex] = value;
}

void Stack::pop() {
    if (empty()) throw std::runtime_error("Stack is empty");
    --topIndex;
}

int Stack::top() const {
    if (empty()) throw std::runtime_error("Stack is empty");
    return data[topIndex];
}

bool Stack::empty() const {
    return topIndex == -1;
}

int Stack::size() const {
    return topIndex + 1;
}
