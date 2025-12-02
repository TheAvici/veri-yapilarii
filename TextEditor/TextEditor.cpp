#include "TextEditor.h"
#include <iostream>

TextEditor::TextEditor()
    : head(nullptr), tail(nullptr), current(nullptr) {}

TextEditor::~TextEditor() {
    TextStateNode* cur = head;
    while (cur) {
        TextStateNode* next = cur->next;
        delete cur;
        cur = next;
    }
}

void TextEditor::removeForward(TextStateNode* from) {
    TextStateNode* cur = from;
    while (cur) {
        TextStateNode* next = cur->next;
        delete cur;
        cur = next;
    }
    if (from && from->prev) {
        from->prev->next = nullptr;
        tail = from->prev;
    }
}

void TextEditor::type(const std::string& newText) {
    if (current && current->next) {
        removeForward(current->next);
    }

    TextStateNode* node = new TextStateNode(newText);
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    current = node;

    std::cout << "Yeni metin: \"" << newText << "\"\n";
}

void TextEditor::undo() {
    if (current && current->prev) {
        current = current->prev;
        std::cout << "Undo -> \"" << current->text << "\"\n";
    } else {
        std::cout << "Undo yapilamaz.\n";
    }
}

void TextEditor::redo() {
    if (current && current->next) {
        current = current->next;
        std::cout << "Redo -> \"" << current->text << "\"\n";
    } else {
        std::cout << "Redo yapilamaz.\n";
    }
}

void TextEditor::show() const {
    if (current) {
        std::cout << "Aktif metin: \"" << current->text << "\"\n";
    } else {
        std::cout << "Metin yok.\n";
    }
}
