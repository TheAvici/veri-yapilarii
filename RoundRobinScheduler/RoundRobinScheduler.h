//
// Created by Sedo on 2.12.2025.
//

#ifndef ROUNDROBINSCHEDULER_ROUNDROBINSCHEDULER_H
#define ROUNDROBINSCHEDULER_ROUNDROBINSCHEDULER_H


#include "ProcessNode.h"

class RoundRobinScheduler {
private:
    ProcessNode* tail; // tail->next = head

public:
    RoundRobinScheduler();
    ~RoundRobinScheduler();

    void addProcess(const std::string& name, int burstTime);
    void run(int quantum);
    bool empty() const;
};

#endif //ROUNDROBINSCHEDULER_ROUNDROBINSCHEDULER_H