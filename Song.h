#ifndef SONG_H
#define SONG_H

#include <iostream>
using namespace std;

// ============================================================
// CLASS: Song  (one node in the doubly linked list)
// ============================================================
class Song {
public:
    string title;
    string artist;
    int    duration;   // seconds
    Song* next;       // pointer to next song
    Song* prev;       // pointer to previous song

    // Constructor
    Song(string t, string a, int d) {
        title = t;
        artist = a;
        duration = d;
        next = NULL;
        prev = NULL;
    }

    // Helper: print one song row
    void display(int index) {
        cout << index << ". \"" << title << "\" by " << artist
            << "  [" << duration / 60 << ":";
        if (duration % 60 < 10) cout << "0";
        cout << duration % 60 << "]" << endl;
    }
};

#endif
