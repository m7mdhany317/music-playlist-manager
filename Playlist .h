
#include <iostream>
using namespace std;
#include "Song.h"

// ============================================================
// CLASS: Playlist  (manages the doubly linked list)
// ============================================================
class Playlist {
private:
    Song* head;           // first song
    Song* tail;           // last song
    Song* current;        // currently selected song
    bool   isPlaying;      // play / pause state
    bool   repeatOne;      // repeat current song
    bool   repeatAll;      // repeat entire playlist
    int    songCount;      // total number of songs
    
    public:
        // Constructor & Destructor
        Playlist();
        ~Playlist();

        // Core operations
        void addSong(string title, string artist, int duration);
        void deleteSong(string title);
        void updateSong(string oldTitle, string newTitle,
                        string newArtist, int newDuration);

        // Navigation
        void nextSong();
        void previousSong();

        // Playback control
        void play();
        void pause();
        void shuffle();

        // Modes
        void toggleRepeatOne();
        void toggleRepeatAll();

        // Utility
        void search(string keyword);
        void displayPlaylist();
};
