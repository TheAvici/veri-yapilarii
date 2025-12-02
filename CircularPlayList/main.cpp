#include "CircularPlaylist.h"

int main() {
    CircularPlaylist playlist;
    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");

    playlist.showCurrent();
    playlist.nextSong();
    playlist.nextSong();
    playlist.nextSong();
    playlist.nextSong(); // tekrar basa doner

    return 0;
}
