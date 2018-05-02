/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   

            Program:  Tuner Pro          
            Authors:                              
    
              (c) Syed Arsal Abbas
                  100835968

              (c) Muhmammad Junaid Farooqui
                  100912649
                          
            Due Date:     5-Dec-2017
                                                     */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _Playlist_H
#define _Playlist_H

#include <ostream>
#include <string>
#include <vector>

#include "track.h"


class Playlist {
	/*
	Playlist represents an user playlist of tracks.
	*/
	public:
		Playlist(const string & aPlaylistName); 
		~Playlist(void);
	    int getID();
		string getName();
		void removeTrack(Track & aTrack);
		void addTrack(Track & aTrack);
		vector<Track*> & getTracks();
	    string toString() const;
	
	private:
		string name;
		vector<Track*> tracks;	
		vector<Track*>::iterator findPosition(Track & aTrack);
		Playlist(const Playlist & aPlaylist); //hide copy constructor in private section
};

ostream & operator<<(ostream & out, const Playlist & aPlaylist);

#endif