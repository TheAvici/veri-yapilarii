//
// Created by Sedo on 2.12.2025.
//

#ifndef ROUNDROBINSCHEDULER_PROCESSNODE_H
#define ROUNDROBINSCHEDULER_PROCESSNODE_H

#include <string>

struct ProcessNode {
    std::string name;
    int remainingTime;
    ProcessNode* next;

    ProcessNode(const std::string& n, int t)
        : name(n), remainingTime(t), next(nullptr) {}
};


#endif //ROUNDROBINSCHEDULER_PROCESSNODE_H