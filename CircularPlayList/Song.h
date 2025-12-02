//
// Created by Sedo on 2.12.2025.
//

#ifndef CIRCULARPLAYLIST_SONG_H
#define CIRCULARPLAYLIST_SONG_H

#include <string>

struct Song {
    std::string title;
    Song* next;

    Song(const std::string& t)
        : title(t), next(nullptr) {}
};



#endif //CIRCULARPLAYLIST_SONG_H