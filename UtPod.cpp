// Neha Shah and Dalia Khater
// Lab 5 - UTPod

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Song.h"
#include "UtPod.h"

using namespace std;


UtPod::UtPod() {
    // set size to default value
    songs = nullptr;
    memSize = MAX_MEMORY;

}

UtPod::UtPod(int size) {
    // set size to parameter value
    songs = nullptr;
    if(size > MAX_MEMORY || size <= 0)
        memSize = MAX_MEMORY;
    else{
        memSize = size;
    }
}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory() >= s.getSize()){   // get remaining mem must be larger than the song size
        SongNode* temp;
        temp = new SongNode();                // like a malloc but declares the pointer
        temp->s.setSize(s.getSize());
        temp->s.setTitle(s.getTitle());
        temp->s.setArtist(s.getArtist());
        temp->next = songs;
        songs = temp;
        return SUCCESS;
    }
    else{
        return NO_MEMORY;
    }
}

int UtPod::removeSong(Song const &s) {          // This searches through for a specific song, if equivalent will remove
    if(getTotalMemory() != MAX_MEMORY){
        SongNode* current;
        SongNode* previous;
        previous = songs;
        if(previous == NULL){                   // Check for empty list
            return NOT_FOUND;
        }
        current = previous->next;
        if(previous->s == s){                   // If first element, change head pointer
            songs = previous->next;
            delete(previous);
            return SUCCESS;
        }
        else {
            while (current != nullptr) {        // Otherwise traverse through list
                if (current->s == s) {
                    previous->next = current->next;
                    delete (current);
                    return SUCCESS;
                } else {
                    previous = current;
                    current = current->next;
                }
            }
            return NOT_FOUND;
        }

    }
    else{
        return NOT_FOUND;                       // What should we return if the linked list is empty?
    }

}

void UtPod::shuffle() {
    //This shuffles twice the size
    int shuffleTimes = 2*getNumSongsInUtPod();             //Changing this number for testing purposes
    int ptr1position, ptr2position;
    SongNode* ptr1 = songs;
    SongNode* ptr2 = songs;
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    while(shuffleTimes != 0){
        ptr1 = songs;
        ptr2 = songs;

        ptr1position = (rand() % getNumSongsInUtPod());
        ptr2position = (rand() % getNumSongsInUtPod());

        for(int i = 0; i < ptr1position; i++){
            ptr1 = ptr1->next;
        }

        for(int j = 0; j < ptr2position; j++){
            ptr2 = ptr2->next;
        }

        swapSongs(ptr1,ptr2);

        shuffleTimes--;
    }
}

void UtPod::showSongList() {
    if(songs == nullptr) {
        cout << "Song list is empty!" << endl;
    }
    else{
        SongNode* ptr = songs;
        while(ptr != nullptr){
            cout << ptr->s.getTitle()<< ", " << ptr->s.getArtist() << ", " << ptr->s.getSize() << " MB" << endl;
            ptr = ptr->next;
        }
    }
    cout << endl;
    return;
}

void UtPod::swapSongs(SongNode* ptr1, SongNode* ptr2){
    Song temp;
    temp = ptr1->s;         //Swap two songs
    ptr1->s = ptr2->s;
    ptr2->s = temp;

}

void UtPod::sortSongList() {                     // Check if song overload operators work first - they do work.
    SongNode* sortedPtr = songs;
    SongNode* lowest;
    SongNode* checkPtr;
                                                 // Separate the sorted/unsorted parts of the list
    while(sortedPtr != nullptr){
        lowest = sortedPtr;                      // Set lowest as the first node
        checkPtr = sortedPtr->next;              // Check from second to last node
        while(checkPtr != nullptr){              // Find the lowest of the rest of the song list
            if(checkPtr->s < lowest->s){         // If lower than current lowest, replace lowest
                lowest = checkPtr;
                //cout << "lowest so far is:" << lowest->s.getArtist()<< ", " << lowest->s.getTitle() << endl;
            }
            checkPtr = checkPtr->next;           // check next node until null (end of list)
        }
        swapSongs(sortedPtr,lowest);               // Swap current w/ lowest
        sortedPtr = sortedPtr->next;              // Move to next position
    }

}

int UtPod::getRemainingMemory() {
    int currentMem = getTotalMemory();
    return MAX_MEMORY-currentMem;

}

void UtPod::clearMemory() {
    while(songs != NULL){
        SongNode* temp;
        temp = songs;
        songs = temp->next;
        delete(temp);
    }
}

int UtPod::getTotalMemory(){
    memSize = 0;
    SongNode* temp;
    temp = songs;
    while (temp != NULL){
        memSize = memSize + temp->s.getSize();
        temp = temp->next;
    }
    return memSize;
}

int UtPod::getNumSongsInUtPod(){
    int numSongs = 0;
    SongNode* temp;
    temp = songs;
    while (temp != NULL){
        numSongs++;
        temp = temp->next;
    }
    return numSongs;
}

UtPod::~UtPod(){
    clearMemory();
    // cout << "All clear" << endl;              //For debugging purposes
}
