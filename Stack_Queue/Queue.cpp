#include "Queue.h"
#include <stdexcept>

Queue::Queue()
    : capacity(4), frontIndex(0), rearIndex(-1), count(0) {
    data = new int[capacity];
}

Queue::~Queue() {
    delete[] data;
}

void Queue::resize() {
    int newCap = capacity * 2;
    int* newData = new int[newCap];

    // Eski elemanları yeni diziye sırayla taşı
    for (int i = 0; i < count; ++i) {
        newData[i] = data[(frontIndex + i) % capacity];
    }

    delete[] data;
    data = newData;
    capacity = newCap;
    frontIndex = 0;
    rearIndex = count - 1;
}

void Queue::enqueue(int value) {
    if (count == capacity) {
        resize();
    }
    rearIndex = (rearIndex + 1) % capacity;
    data[rearIndex] = value;
    ++count;
}

void Queue::dequeue() {
    if (empty()) throw std::runtime_error("Queue is empty");
    frontIndex = (frontIndex + 1) % capacity;
    --count;
}

int Queue::front() const {
    if (empty()) throw std::runtime_error("Queue is empty");
    return data[frontIndex];
}

bool Queue::empty() const {
    return count == 0;
}

int Queue::size() const {
    return count;
}
