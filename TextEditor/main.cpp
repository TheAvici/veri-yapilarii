#include "TextEditor.h"

int main() {
    TextEditor editor;
    editor.type("Merhaba");
    editor.type("Merhaba dunya");
    editor.type("Merhaba dunya!!!");

    editor.undo();
    editor.undo();
    editor.redo();
    editor.show();

    return 0;
}
