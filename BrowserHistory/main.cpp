// main.cpp
#include <iostream>
#include "BrowserHistory.h"
#include "Page.h"

int main() {
    BrowserHistory history;

    // 3 tane sayfa ziyaret edelim
    history.visit(Page("https://www.google.com", "Google"));
    history.visit(Page("https://www.github.com", "GitHub"));
    history.visit(Page("https://www.geeksforgeeks.org", "GeeksforGeeks"));

    std::cout << "\n--- Geri Gitme ---\n";
    history.back();      // GfG -> GitHub
    history.back();      // GitHub -> Google
    history.back();      // Daha geri yok

    std::cout << "\n--- İleri Gitme ---\n";
    history.forward();   // Google -> GitHub
    history.forward();   // GitHub -> GfG
    history.forward();   // Daha ileri yok

    std::cout << "\n--- Aktif Sayfa ---\n";
    history.showCurrent();

    // Yeni sayfa ziyaret edelim (ileri geçmişi silinecek)
    std::cout << "\n--- Yeni Ziyaret ---\n";
    history.visit(Page("https://www.youtube.com", "YouTube"));
    history.showCurrent();

    std::cout << "\n--- Geri / İleri Testi ---\n";
    history.back();
    history.showCurrent();
    history.forward();
    history.showCurrent();

    return 0;
}
