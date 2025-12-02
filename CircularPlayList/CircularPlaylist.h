//
// Created by Sedo on 2.12.2025.
//

#ifndef CIRCULARPLAYLIST_SINGULARPLAYLIST_H
#define CIRCULARPLAYLIST_SINGULARPLAYLIST_H

#include "Song.h"

class CircularPlaylist {
private:
    Song* tail;    // tail->next = head
    Song* current; // o an çalan şarkı

public:
    CircularPlaylist();
    ~CircularPlaylist();

    void addSong(const std::string& title);
    void nextSong();
    void showCurrent() const;
};



#endif //CIRCULARPLAYLIST_SINGULARPLAYLIST_H