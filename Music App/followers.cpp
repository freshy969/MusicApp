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
#include <vector>

using namespace std;

#include "follow.h"
#include "followers.h"
	
Followers::Followers(){

}

Followers::~Followers(void){
	for(int i=0; i<collection.size(); i++)
	   delete collection[i]; //delete Users in this container
}

vector<Follow*> Followers::getCollection(){
	return collection; //return copy of collection
}

Follow * Followers::find(Playlist * findPlaylist) {
	for (vector<Follow*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
		if((*itr)->getPlaylist() == findPlaylist) 
			return *itr;
	return NULL;
}

vector<Follow*>::iterator Followers::findPosition(Follow & aFollow)  {
	for (vector<Follow*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aFollow) 
			return it;
	return collection.end();
}

void Followers::add(Follow & aFollow){
	collection.push_back(&aFollow);
}

void Followers::remove(Follow & aFollow){
	vector<Follow*>::iterator itr = findPosition(aFollow);
	if(itr != collection.end()){
		Follow * theFollow = *itr;
		collection.erase(itr);
		delete theFollow; //free the memory of theUser
	}
}