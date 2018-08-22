/* * * * * * * * * * * * * * * * * * * * * * * * * * */
                                           
            Program:  Tuner Pro          
            Authors:                              
    
              (c) Syed Arsal Abbas

                                                     
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _Follow_H
#define _Follow_H

#include <ostream>
#include <string>
#include <vector>

#include "playlist.h"

class Follow {
	public:
		Follow(const string & aPlaylistName,Playlist * aplaylist); 
		~Follow(void);
	    int getID();
	    string getName();
	    Playlist * getPlaylist();
		Playlist * findfollower(Playlist * aPlaylistName);
		void removefollower(Playlist & aPlayList);
		void addfollower(Playlist & aPlayList);
		void removeTrack(Track & aTrack);
	    void addTrack(Track & aTrack);
	    string toString() const;
	
	private:
		static int nextFollowNumericID;
		int id; //numeric id for uniformity with other model classes
		string name;
		Playlist* myplaylist;
		vector<Playlist*> followers;
		vector<Playlist*>::iterator findPosition(Playlist & aPlaylist);
};

ostream & operator<<(ostream & out, const Follow & aFollow);

#endif