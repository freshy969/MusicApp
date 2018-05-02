/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   

            Program:  Tuner Pro Search Engine          
            Authors:                              
    
              (c) Syed Arsal Abbas
                  100835968

              (c) Muhmammad Junaid Farooqui
                  100912649
                          
            Due Date: 5-Dec-2017
                                                     */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include<bits/stdc++.h>

using namespace std;

//DR- 

vector<int> intersection(vector<int> &v1, vector<int> &v2){
    
    vector<int> v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

    return v3;
}

int main(){
	string line;
	ifstream infile;
	
	string temp;
	
	map<string,int> line_to_int;
	map<string,int>::iterator val;

	map<int,string> int_to_line;
	
	map<string,vector<int> > word_to_list;
	map<string,vector<int> >::iterator wl;
	
	  
	infile.open ("inputPartII.txt");
	int count=0;
	
    while(!infile.eof()){
    	// To get you all the lines.

        getline(infile,line); // Saves the line in STRING.
        if(line[0]=='/' && line[1]=='/'){
        	continue;
		}
		
		if(line[5]=='r' || line[5]=='s'){
		
			int start=line.find("\"");
			int end=line.find("\"",start+1);
			temp = line.substr(start+1,end-start-1);
			val = line_to_int.find(temp);
			
			if(val==line_to_int.end()){
				line_to_int.insert(pair<string,int>(temp,count));
				int_to_line.insert(pair<int,string>(count,temp));
				vector<string> tokens;
				string token;
				istringstream tokenStream(temp);
			    
			    while (getline(tokenStream, token, ' ')){
			       //tokens.push_back(token);			       
			       //cout<<token<<" ";
			       for (std::size_t i=0;i<token.size();i++)
     					if (ispunct(token[i])) 
     						token.erase(token.find_first_of(token[i]));
     				
			       transform(token.begin(), token.end(), token.begin(), ::tolower);
			       wl = word_to_list.find(token);
			       //cout<<token<<endl;
			       if(wl != word_to_list.end()){
			       		wl->second.push_back(count);
				   }
				   else{
				   		vector<int> t;
				   		t.push_back(count);
				   		word_to_list.insert(pair<string,vector<int> >(token,t));
				   }
			    }
			    //cout<<endl;
				count++;
				//cout<<count<<endl;
			}
			//cout<<temp<<endl;
		}		
        //cout<<line<<endl; // Prints out STRING.
    }
    
    string input;
	cout<<"Enter a song (or a word in a song) you want to search: " << endl;
	getline(cin,input);
	
	string tok;
	istringstream tokenStream(input);
	vector<vector<int> > final; 
	
	while (getline(tokenStream, tok, ' ')){
		
		cout<<"Parsed Command: "<<tok<< "\n"<<endl;
		cout<<"These are the songs that contain the word '"<<tok<< "' :"<<endl;

		transform(tok.begin(), tok.end(), tok.begin(), ::tolower);	
		wl = word_to_list.find(tok);
		
		if(wl!=word_to_list.end()){
			vector<int> result = word_to_list.find(tok)->second;
			final.push_back(result);

		}
 	}
 	
 	vector<int> tempp;
 	tempp = final[0];
 	
 	for(std::size_t i=1;i<final.size();i++){
 		tempp = intersection(tempp,final[i]);
	}
	
	for(std::size_t i=0;i<tempp.size();i++){
 		cout<<int_to_line.find(tempp[i])->second<<endl;
	}
	 	  
	infile.close();

}