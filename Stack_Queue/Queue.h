//
// Created by Sedo on 2.12.2025.
//

#ifndef STACK_QUEUE_QUEUE_H
#define STACK_QUEUE_QUEUE_H


class Queue {
private:
    int* data;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

    void resize();

public:
    Queue();
    ~Queue();

    void enqueue(int value);
    void dequeue();
    int front() const;
    bool empty() const;
    int size() const;
};




#endif //STACK_QUEUE_QUEUE_H