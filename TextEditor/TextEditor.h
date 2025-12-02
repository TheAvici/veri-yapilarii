//
// Created by Sedo on 2.12.2025.
//

#ifndef TEXTEDITOR_TEXTEDITOR_H
#define TEXTEDITOR_TEXTEDITOR_H


#include "TextStateNode.h"

class TextEditor {
private:
    TextStateNode* head;
    TextStateNode* tail;
    TextStateNode* current;

    void removeForward(TextStateNode* from);

public:
    TextEditor();
    ~TextEditor();

    void type(const std::string& newText);
    void undo();
    void redo();
    void show() const;
};



#endif //TEXTEDITOR_TEXTEDITOR_H