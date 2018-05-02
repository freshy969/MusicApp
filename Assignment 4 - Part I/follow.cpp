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

#include <iostream>
#include <string>

using namespace std;

#include "follow.h"

int Follow::nextFollowNumericID = 1000;
	
Follow::Follow(const string & aPlaylistName,Playlist *aPlaylist){
	myplaylist=aPlaylist;
	name = aPlaylistName;
	id = nextFollowNumericID++;
}

Follow::~Follow(){
	cout << "~Follow(void)" << endl;
	//follow objects own followers
	for(int i=0; i<followers.size(); i++)
		delete followers[i];
}

int Follow::getID(){
	return id;
}

string Follow::getName(){
	return name;
}

Playlist * Follow::getPlaylist(){ 
	return myplaylist;
}

vector<Playlist*>::iterator Follow::findPosition(Playlist & aPlaylist){
	for (vector<Playlist*>::iterator itr = followers.begin() ; itr != followers.end(); ++itr)
		if(*itr == &aPlaylist) 
			return itr;
	return followers.end();
}

Playlist* Follow::findfollower(Playlist * aPlaylistName){
	for (vector<Playlist*>::iterator itr = followers.begin() ; itr != followers.end(); ++itr)
		if(((*itr)==aPlaylistName)) 
			return *itr;
	return NULL;
}

void Follow::addfollower(Playlist & aPlaylist){
	//add playlist if it does not already exist
	vector<Playlist*>::iterator itr = findPosition(aPlaylist);
	if(itr == followers.end()) {
		followers.push_back(&aPlaylist);
	}
	vector<Track*> & tracks=(myplaylist)->getTracks();
	for (vector<Track*>::iterator itr = tracks.begin() ; itr != tracks.end(); ++itr){
		(aPlaylist).addTrack(**itr);
	}
}

void Follow::removefollower(Playlist & aPlaylist){
	vector<Playlist*>::iterator itr = findPosition(aPlaylist);
	if(itr != followers.end()) {
	   followers.erase(itr);
	}
}

void Follow::addTrack(Track & aTrack){
	for (vector<Playlist*>::iterator itr = followers.begin() ; itr != followers.end(); ++itr){
		Playlist * playlist = *itr;
		playlist->addTrack(aTrack);
	}

}

void Follow::removeTrack(Track & aTrack){
	for (vector<Playlist*>::iterator itr = followers.begin() ; itr != followers.end(); ++itr){
		Playlist * playlist = *itr;
		playlist->removeTrack(aTrack);
	}

}

string Follow::toString()const {
	string indent = "     ";
	string s;
	s.append(name);
	s.append("\n");
	s.append(indent + "Followers:\n");
	for (vector<Playlist*>::size_type i = 0 ; i < followers.size(); i++){
		s.append(indent + to_string(i) + " " + (followers[i])->toString() + "\n");
		s.append("\n");
	}
	return s;
}

ostream & operator<<(ostream & out, const Follow & aFollow){
	out << aFollow.toString() << endl;
	return out;
}