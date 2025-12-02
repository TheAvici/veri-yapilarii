#ifndef YZM209_ODEV_2_SONG_H
#define YZM209_ODEV_2_SONG_H
using namespace std;

struct Song {
    string title;
    string artist;

    Song() {}

    Song(string t, string a) {
        title = t;
        artist = a;
    }
};

#endif //YZM209_ODEV_2_SONG_H