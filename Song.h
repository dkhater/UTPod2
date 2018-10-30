// Neha Shah and Dalia Khater
// Lab 5 - UTPod


#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HW5_UTPOD_SONG_H
#define HW5_UTPOD_SONG_H

#endif //HW5_UTPOD_SONG_H

//This is the song class. The functions in song class either set or get the artist, title, or song size.
//The comparison for songs (operator overloads) are also here.

#ifndef SONG_H
#define SONG_H

//Song class declaration
class Song
{
    private:
        string artist;
        string title;
        int songSize;

    public:
        Song();                                 // These are the constructors (default and with parameters)
        Song(string, string, int);

        void setArtist(string);                 // These are the public song class functions
        void setTitle(string);
        void setSize(int);
        string getArtist() const;
        string getTitle() const;
        int getSize() const;

        bool operator >(Song const &rhs);       //These are the operator overloads
        bool operator <(Song const &rhs);
        bool operator ==(Song const &rhs);

};

#endif
