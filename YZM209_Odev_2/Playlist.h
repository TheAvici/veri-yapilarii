#ifndef YZM209_ODEV_2_PLAYLIST_H
#define YZM209_ODEV_2_PLAYLIST_H

#include <string>
#include "Song.h"
#include "Node.h"
using namespace std;

class PlayList {
private:
    Node *head;
    Node *currentSong;
    bool isRepeat;

public:
    PlayList();
    ~PlayList();

    void addSong(Song song);
    bool removeSong(string title);
    void playCurrent();
    void nextSong();
    void prevSong();
    void toggleRepeat();
    void printPlaylist();
};
#endif //YZM209_ODEV_2_PLAYLIST_H