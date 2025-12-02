#ifndef YZM209_ODEV_2_NODE_H
#define YZM209_ODEV_2_NODE_H

struct Node {
    Song data;
    Node *next;
    Node *prev;

    Node(Song s) {
        data = s;
        next = nullptr;
        prev = nullptr;
    }
};

#endif //YZM209_ODEV_2_NODE_H