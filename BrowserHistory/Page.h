//
// Created by Sedo on 2.12.2025.
//

#ifndef BROWSERHISTORY_PAGE_H
#define BROWSERHISTORY_PAGE_H


#include <string>

struct Page {
    std::string url;
    std::string title;

    Page(const std::string& u = "", const std::string& t = "")
        : url(u), title(t) {}
};

#endif //BROWSERHISTORY_PAGE_H