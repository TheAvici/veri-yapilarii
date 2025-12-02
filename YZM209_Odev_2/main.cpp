#include <iostream>
#include "Playlist.h"
#include <limits>
#include <string>

int main() {
    PlayList sedolist;

    cout << "----------TEST-------" << endl;
    cout << "\n**** addSong fonkiyon testi ****" << endl;

    sedolist.addSong(Song("Sickly Sweet", "NewDad"));
    sedolist.addSong(Song("Sweet Sacrifice", "Evanescence"));
    sedolist.addSong(Song("Tonight(demo)", "Amira Elfeky"));
    sedolist.addSong(Song("Mevsim Sonbahar", "Metro"));
    sedolist.addSong(Song("Decadence", "Disturbed"));
    sedolist.addSong(Song("Lascivious", "Soen"));
    sedolist.addSong(Song("So Far Away", "Avenged Sevenfold"));
    sedolist.addSong(Song("Lucidity", "Soen"));\

    cout << "\n**** printPlayList fonkiyon testi ****" << endl;
    sedolist.printPlaylist();

    cout << "\n**** playCurrent fonkiyon testi ****" << endl;
    sedolist.playCurrent();

    cout << "\n**** nextSong fonkiyon testi ****" << endl;
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();

    cout << "\n**** toggleRepeat fonkiyon testi ****" << endl;
    sedolist.toggleRepeat();

    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();
    sedolist.nextSong();

    cout << "\n**** Prevsong fonkiyon testi ****" << endl;
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();

    sedolist.toggleRepeat();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();
    sedolist.prevSong();

    cout << "\n**** removeSong fonkiyon testi ****" << endl;
    sedolist.removeSong("Decadence");

    sedolist.printPlaylist();

    cout << "----------TEST BITTI-------" << endl;


    PlayList muziklist;
    int secim;
    while (true) {
        cout << "\n----- MUZIK CALAR -----" << endl;
        cout << "1. Sarki Ekle" << endl;
        cout << "2. Sarki Sil" << endl;
        cout << "3. Listeyi Goster" << endl;
        cout << "4. Simdi Calani Oynat" << endl;
        cout << "5. Sonraki Sarki" << endl;
        cout << "6. Onceki Sarki" << endl;
        cout << "7. Tekrar Modunu Degistir" << endl;
        cout << "0. Cikis" << endl;
        cout << "--------------------------------" << endl;
        cout << "Seciminiz: ";

        cin >> secim;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (secim) {
            case 1: {
                string title, artist;
                cout << "----- Yeni Sarki Ekle -----" << endl;
                cout << "Sarki Adi: ";
                getline(cin, title);

                cout << "Sanatci: ";
                getline(cin, artist);
                muziklist.addSong(Song(title, artist));
                break;
            }
            case 2: {
                string title;
                cout << "----- Sarki Sil -----" << endl;
                cout << "Silinecek Sarki Adi: ";
                getline(cin, title);
                muziklist.removeSong(title);
                break;
            }
            case 3: {
                cout << "----- Muzik Listesi -----" << endl;
                muziklist.printPlaylist();
                break;
            }
            case 4: {
                cout << "----- Su An Calan Sarki" << endl;
                muziklist.playCurrent();
                break;
            }
            case 5: {
                cout << "----- Sonraki Sarkiya Geciliyor... -----" << endl;
                muziklist.nextSong();
                break;
            }
            case 6: {
                cout << "----- Onceki Sarkiya Geciliyor... -----" << endl;
                muziklist.prevSong();
                break;
            }
                case 7: {
                cout << "----- Tekrar Modunu Degistirildi -----" << endl;
                muziklist.toggleRepeat();
                break;
            }
            case 0: {
                cout << "----- Cikis Yapiliyor... -----" << endl;
                return 0;
            }
        }
    }

    return 0;

}
