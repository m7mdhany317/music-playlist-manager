#include <iostream>
using namespace std;
#include "Song.h"
#include "Playlist.h"

// ============================================================
// CLASS: Playlist  (manages the doubly linked list)
// ============================================================

// Constructor
Playlist::Playlist() {
    head = NULL;
    tail = NULL;
    current = NULL;
    isPlaying = false;
    repeatOne = false;
    repeatAll = false;
    songCount = 0;
    srand((unsigned int)time(0));   // seed random
}

// Destructor ó free all nodes
Playlist::~Playlist() {
    Song* temp = head;
    while (temp != NULL) {
        Song* next = temp->next;
        delete temp;
        temp = next;
    }
}

// ----------------------------------------------------------
// 1. ADD a song at the end of the list
// ----------------------------------------------------------
void Playlist::addSong(string title, string artist, int duration) {
    Song* newSong = new Song(title, artist, duration);

    if (head == NULL) {
        // List is empty
        head = newSong;
        tail = newSong;
        current = newSong;   // auto-select first song
    }
    else {
        // Link at the tail
        newSong->prev = tail;
        tail->next = newSong;
        tail = newSong;
    }
    songCount++;
    cout << "[+] Added: \"" << title << "\" by " << artist << endl;
}

// ----------------------------------------------------------
// 2. DELETE a song by title
// ----------------------------------------------------------
void Playlist::deleteSong(string title) {
    Song* temp = head;

    while (temp != NULL) {
        if (temp->title == title) {
            // Fix current pointer if needed
            if (temp == current) {
                if (temp->next != NULL)
                    current = temp->next;
                else if (temp->prev != NULL)
                    current = temp->prev;
                else
                    current = NULL;
                isPlaying = false;
            }

            // Fix prev node's next pointer
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;  // deleting head

            // Fix next node's prev pointer
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            else
                tail = temp->prev;  // deleting tail

            delete temp;
            songCount--;
            cout << "[-] Deleted: \"" << title << "\"" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "[!] Song \"" << title << "\" not found." << endl;
}

// ----------------------------------------------------------
// 3. UPDATE a song's info by title
// ----------------------------------------------------------
void Playlist::updateSong(string oldTitle, string newTitle,
    string newArtist, int newDuration) {
    Song* temp = head;
    while (temp != NULL) {
        if (temp->title == oldTitle) {
            temp->title = newTitle;
            temp->artist = newArtist;
            temp->duration = newDuration;
            cout << "[*] Updated: \"" << oldTitle
                << "\" -> \"" << newTitle << "\"" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "[!] Song \"" << oldTitle << "\" not found." << endl;
}

// ----------------------------------------------------------
// 4. NEXT song
// ----------------------------------------------------------
void Playlist::nextSong() {
    if (current == NULL) {
        cout << "[!] Playlist is empty." << endl;
        return;
    }
    if (repeatOne) {
        cout << "[>>] Repeating: ";
        current->display(0);
        return;
    }
    if (current->next != NULL) {
        current = current->next;
    }
    else if (repeatAll) {
        current = head;   // wrap to beginning
    }
    else {
        cout << "[!] Already at last song." << endl;
        isPlaying = false;
        return;
    }
    cout << "[>>] Next: ";
    current->display(0);
}

// ----------------------------------------------------------
// 5. PREVIOUS song
// ----------------------------------------------------------
void Playlist::previousSong() {
    if (current == NULL) {
        cout << "[!] Playlist is empty." << endl;
        return;
    }
    if (repeatOne) {
        cout << "[<<] Repeating: ";
        current->display(0);
        return;
    }
    if (current->prev != NULL) {
        current = current->prev;
    }
    else if (repeatAll) {
        current = tail;   // wrap to end
    }
    else {
        cout << "[!] Already at first song." << endl;
        return;
    }
    cout << "[<<] Previous: ";
    current->display(0);
}

// ----------------------------------------------------------
// 6. PLAY current song
// ----------------------------------------------------------
void Playlist::play() {
    if (current == NULL) {
        cout << "[!] No song to play. Add songs first." << endl;
        return;
    }
    isPlaying = true;
    cout << "[PLAY] Now playing: \"" << current->title
        << "\" by " << current->artist << endl;
}

// ----------------------------------------------------------
// 7. PAUSE current song
// ----------------------------------------------------------
void Playlist::pause() {
    if (!isPlaying) {
        cout << "[!] No song is currently playing." << endl;
        return;
    }
    isPlaying = false;
    cout << "[PAUSE] Paused: \"" << current->title << "\"" << endl;
}

// ----------------------------------------------------------
// 8. SHUFFLE ó move to a random song
// ----------------------------------------------------------
void Playlist::shuffle() {
    if (songCount == 0) {
        cout << "[!] Playlist is empty." << endl;
        return;
    }
    int randomIndex = rand() % songCount;
    Song* temp = head;
    for (int i = 0; i < randomIndex; i++) {
        temp = temp->next;
    }
    current = temp;
    isPlaying = true;
    cout << "[SHUFFLE] Jumped to: \"" << current->title
        << "\" by " << current->artist << endl;
}

// ----------------------------------------------------------
// 9. TOGGLE repeat modes
// ----------------------------------------------------------
void Playlist::toggleRepeatOne() {
    repeatOne = !repeatOne;
    if (repeatOne) repeatAll = false;   // can't have both
    cout << "[REPEAT-ONE] " << (repeatOne ? "ON" : "OFF") << endl;
}

void Playlist::toggleRepeatAll() {
    repeatAll = !repeatAll;
    if (repeatAll) repeatOne = false;
    cout << "[REPEAT-ALL] " << (repeatAll ? "ON" : "OFF") << endl;
}

// ----------------------------------------------------------
// 10. SEARCH by title OR artist (case-sensitive)
// ----------------------------------------------------------
void Playlist::search(string keyword) {
    cout << "\n--- Search results for: \"" << keyword << "\" ---" << endl;
    Song* temp = head;
    int   index = 1;
    bool  found = false;

    while (temp != NULL) {
        // Check if keyword appears in title or artist
        if (temp->title.find(keyword) != string::npos ||
            temp->artist.find(keyword) != string::npos) {
            temp->display(index);
            found = true;
        }
        index++;
        temp = temp->next;
    }
    if (!found)
        cout << "[!] No results found." << endl;
    cout << "--------------------------------------" << endl;
}

// ----------------------------------------------------------
// 11. DISPLAY full playlist
// ----------------------------------------------------------
void Playlist::displayPlaylist() {
    if (head == NULL) {
        cout << "[!] Playlist is empty." << endl;
        return;
    }
    cout << "\n============= PLAYLIST (" << songCount << " songs) =============" << endl;
    Song* temp = head;
    int   index = 1;
    while (temp != NULL) {
        if (temp == current)
            cout << " >> ";   // mark current song
        else
            cout << "    ";
        temp->display(index);
        index++;
        temp = temp->next;
    }
    cout << "Status : " << (isPlaying ? "Playing" : "Paused") << endl;
    cout << "Repeat1: " << (repeatOne ? "ON" : "OFF")
        << "   RepeatAll: " << (repeatAll ? "ON" : "OFF") << endl;
    cout << "==========================================" << endl;
}
