# Music Playlist Manager

A **console-based music player simulation** built in C++ using **Object-Oriented Programming (OOP)** principles and **Doubly Linked List** data structure.

## 📋 Features

### Core CRUD Operations
- ✅ **Add Song** - Insert songs at the end of the playlist
- ✅ **Delete Song** - Remove songs by title with intelligent pointer management
- ✅ **Update Song** - Modify song details (title, artist, duration)
- ✅ **Search** - Find songs by title or artist (substring matching)

### Playback Controls
- ▶️ **Play** - Start playing the current song
- ⏸️ **Pause** - Pause the currently playing song
- ⏭️ **Next Song** - Move to the next song with repeat mode support
- ⏮️ **Previous Song** - Navigate to the previous song
- 🔀 **Shuffle** - Jump to a random song in the playlist

### Repeat Modes
- 🔁 **Repeat-One** - Continuously repeat the current song
- 🔁 **Repeat-All** - Loop through the entire playlist

### Playlist Management
- 📊 **Display Playlist** - View all songs with current playback status
- 🎵 **Song Count** - Track total number of songs

## 🛠️ Technical Architecture

### Data Structure: Doubly Linked List
Each song is stored as a node in a **doubly linked list**, enabling:
- **Bidirectional Traversal** - Navigate forward and backward
- **O(1) Insertion/Deletion** - Efficient at tail and current position
- **Dynamic Memory Management** - No fixed playlist size limit

### Class Hierarchy
```
Song (Node)
  ├─ title: string
  ├─ artist: string
  ├─ duration: int (seconds)
  ├─ next: Song*
  └─ prev: Song*

Playlist (Manager)
  ├─ head, tail, current pointers
  ├─ playback state flags
  └─ core operations
```

## 📁 Project Structure

```
music-playlist-manager/
├── Song.h              # Song class header (node structure)
├── Playlist.h          # Playlist class header
├── Playlist.cpp        # Playlist implementation
├── main.cpp            # Entry point with menu system
├── Makefile            # Build automation
├── .gitignore          # Git ignore rules
└── README.md           # This file
```

## 🚀 Getting Started

### Quick Compilation with Makefile
```bash
make              # Compile the project
make run          # Compile and run
make clean        # Remove build artifacts
```

### Manual Compilation
```bash
g++ -o playlist main.cpp Playlist.cpp -std=c++11
./playlist
```

### Sample Interaction
```
========= MUSIC PLAYLIST MANAGER =========
 1. Add song          2. Delete song
 3. Update song       4. Display playlist
 5. Play              6. Pause
 7. Next song         8. Previous song
 9. Shuffle          10. Toggle Repeat-One
11. Toggle Repeat-All 12. Search
 0. Exit
==========================================
Choice: 4

============= PLAYLIST (4 songs) =============
    1. "Blinding Lights" by The Weeknd  [3:20]
    2. "Kadaba" by Karim Osama  [3:54]
 >> 3. "AGBHA" by Ziad Zaza  [3:23]
    4. "El Neyya" by Lege-Cy  [2:21]
Status : Paused
Repeat1: OFF   RepeatAll: OFF
==========================================
```

## 💡 Key Implementation Details

### Memory Management
- **Dynamic Allocation**: Songs are created with `new` operator
- **Proper Cleanup**: Destructor iterates through list freeing all nodes
- **Pointer Updates**: All pointer references updated on deletion to prevent dangling pointers

### Repeat Modes
- **Repeat-One**: Prevents advancing to next song; stays on current
- **Repeat-All**: Wraps to beginning when reaching the end
- **Mutual Exclusivity**: Cannot have both modes enabled simultaneously

### Search Functionality
- Uses `string::find()` for substring matching
- Searches both title and artist fields
- Case-sensitive matching

## 🎯 Time Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Add Song | O(1) |
| Delete Song | O(n) |
| Search Song | O(n) |
| Update Song | O(n) |
| Next/Previous | O(1) |
| Shuffle | O(n) |

## 🔧 Technologies Used
- **Language**: C++11
- **Data Structure**: Doubly Linked List
- **Paradigm**: Object-Oriented Programming (OOP)
- **Features**: Encapsulation, Constructors/Destructors, Dynamic Memory

## 📝 Sample Songs (Pre-loaded)
1. "Blinding Lights" by The Weeknd (3:20)
2. "Kadaba" by Karim Osama (3:54)
3. "AGBHA" by Ziad Zaza (3:23)
4. "El Neyya" by Lege-Cy (2:21)

## 🎓 Learning Outcomes
This project demonstrates:
- ✅ Doubly linked list implementation
- ✅ Pointer manipulation and memory management
- ✅ Class design and encapsulation
- ✅ User interface design
- ✅ State management in applications

## 📄 License
Open source - Feel free to use and modify for educational purposes.

---

**Author**: m7mdhany317  
**Status**: ✅ Complete and Ready for Production
