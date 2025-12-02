//
// Created by Sedo on 2.12.2025.
//

#ifndef TEXTEDITOR_TEXTSTATENODE_H
#define TEXTEDITOR_TEXTSTATENODE_H


#include <string>

struct TextStateNode {
    std::string text;
    TextStateNode* prev;
    TextStateNode* next;

    TextStateNode(const std::string& t)
        : text(t), prev(nullptr), next(nullptr) {}
};


#endif //TEXTEDITOR_TEXTSTATENODE_H