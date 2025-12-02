//
// Created by Sedo on 2.12.2025.
//

#ifndef BROWSERHISTORY_BROWSERHISTORY_H
#define BROWSERHISTORY_BROWSERHISTORY_H


#include "Node.h"

class BrowserHistory {
private:
    Node* head;
    Node* tail;
    Node* current;

    void removeForward(Node* from);

public:
    BrowserHistory();
    ~BrowserHistory();

    void visit(const Page& page);
    void back();
    void forward();
    void showCurrent() const;
};




#endif //BROWSERHISTORY_BROWSERHISTORY_H