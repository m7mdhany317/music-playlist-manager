
#include <iostream>
#include <string>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
using namespace std;


#include "Playlist.h"


// ============================================================
// MENU ó text-based interface
// ============================================================
void showMenu() {
    cout << "\n========= MUSIC PLAYLIST MANAGER =========" << endl;
    cout << " 1. Add song          2. Delete song" << endl;
    cout << " 3. Update song       4. Display playlist" << endl;
    cout << " 5. Play              6. Pause" << endl;
    cout << " 7. Next song         8. Previous song" << endl;
    cout << " 9. Shuffle          10. Toggle Repeat-One" << endl;
    cout << "11. Toggle Repeat-All 12. Search" << endl;
    cout << " 0. Exit" << endl;
    cout << "===========================================" << endl;
    cout << "Choice: ";
}

// ============================================================
// MAIN
// ============================================================
int main() {
    Playlist myPlaylist;
    int choice;

    // Pre-load a few sample songs so the user can test right away
    myPlaylist.addSong("Blinding Lights", "The Weeknd", 200);
    myPlaylist.addSong("Kadaba", "Karim Osama", 234);
    myPlaylist.addSong("AGBHA", "Ziad Zaza", 203);
    myPlaylist.addSong("El Neyya", "Lege-Cy", 141);

    do {
        showMenu();
        cin >> choice;
        cin.ignore();   // clear newline left in buffer

        if (choice == 1) {
            // ADD
            string title, artist;
            int    duration;
            cout << "Title   : "; getline(cin, title);
            cout << "Artist  : "; getline(cin, artist);
            cout << "Duration (seconds): "; cin >> duration; cin.ignore();
            myPlaylist.addSong(title, artist, duration);

        }
        else if (choice == 2) {
            // DELETE
            string title;
            cout << "Title to delete: "; getline(cin, title);
            myPlaylist.deleteSong(title);

        }
        else if (choice == 3) {
            // UPDATE
            string oldTitle, newTitle, newArtist;
            int    newDuration;
            cout << "Current title   : "; getline(cin, oldTitle);
            cout << "New title       : "; getline(cin, newTitle);
            cout << "New artist      : "; getline(cin, newArtist);
            cout << "New duration (s): "; cin >> newDuration; cin.ignore();
            myPlaylist.updateSong(oldTitle, newTitle, newArtist, newDuration);

        }
        else if (choice == 4) {
            myPlaylist.displayPlaylist();

        }
        else if (choice == 5) {
            myPlaylist.play();

        }
        else if (choice == 6) {
            myPlaylist.pause();

        }
        else if (choice == 7) {
            myPlaylist.nextSong();

        }
        else if (choice == 8) {
            myPlaylist.previousSong();

        }
        else if (choice == 9) {
            myPlaylist.shuffle();

        }
        else if (choice == 10) {
            myPlaylist.toggleRepeatOne();

        }
        else if (choice == 11) {
            myPlaylist.toggleRepeatAll();

        }
        else if (choice == 12) {
            string keyword;
            cout << "Search keyword: "; getline(cin, keyword);
            myPlaylist.search(keyword);

        }
        else if (choice == 0) {
            cout << "Goodbye!" << endl;

        }
        else {
            cout << "[!] Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}