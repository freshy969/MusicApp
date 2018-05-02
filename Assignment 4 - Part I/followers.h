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

#ifndef _Followers_H
#define _Followers_H

#include <ostream>
#include <vector>
#include <string>

using namespace std;

#include "UI.h"
#include "follow.h"



class Followers {
	public:
		Followers(); 
		~Followers(void);
		Follow * find(Playlist * findPlaylist);
		vector<Follow*> getCollection();
		void add(Follow & aFollow);
		void remove(Follow & aFollow);
	
	private:
		vector<Follow*> collection;
		vector<Follow*>::iterator findPosition(Follow & aFollow);
};

#endif