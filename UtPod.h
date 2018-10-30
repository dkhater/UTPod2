// Neha Shah and Dalia Khater
// Lab 5 - UTPod

#include <cstdlib>
#include <iostream>


using namespace std;

#ifndef HW5_UTPOD_UTPOD_H
#define HW5_UTPOD_UTPOD_H

#endif //HW5_UTPOD_UTPOD_H

//This is UtPod.h which declares the UtPod class all all the functions/variables associated with it.

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod {
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

    void swapSongs(SongNode *ptr1, SongNode *ptr2);

public:
    //Default constructor
    //set the memory size to MAX_MEMORY
    UtPod();

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.
    UtPod(int size);


    /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song
       precondition: s is a valid Song
       input parameters - takes in a song
       output parameters - creates a song node from song and pushed it onto linked list
    */
    int addSong(Song const &s);

    /* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -1 if nothing is removed
         input parameters - which song to remove?
         output parameters - song is removed, previous node points to next node, memory is free
    */
    int removeSong(Song const &s);

    /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list
         input parameters - none
         output parameters - nothing returned, but song list is shuffled by 2*(number of songs in list) times
      */
    void shuffle();

    /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)
         input parameters - none
         output parameters - prints the title of the song, then the artist, then the size in MB; no return
    */
    void showSongList();

    /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list
         input parameters - none
         output parameters -  no return, rearranges the song list alphabetically based on artist, title, and ascending numbers
    */
    void sortSongList();

    /* FUNCTION - void clearMemory
   * clears all the songs from memory
     input parameters -  no input, just checks if head is
     output parameters - clears all the songs, does not return anything
  */
    void clearMemory();

    /* FUNCTION - int getTotalMemory
    *  returns the amount of memory used
    input parameters - none
    output parameters - returns the amount of memory used in current Utpod
    */
    int getTotalMemory();

    /* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs
    input parameters - none
    output parameters - returns the amount of memory left
    */
    int getRemainingMemory();

    /* FUNCTION - int getNumSongsInUtPod
     *  returns the number of songs in the utpod
    input parameters - none
    output parameters - returns the number of nodes in the linked list
    */
    int getNumSongsInUtPod();

    ~UtPod();

};

#endif
