#=============================
#
#	Code Written by:
#    
#   Syed Arsal Abbas
#   100835968
#
#   Muhmammad Junaid Farooqui
#   100912649
# 	
#=============================

OBJ = command.o follow.o followers.o main.o mytunes.o playlist.o recording.o recordings.o str_util.o song.o songs.o track.o tracks.o UI.o user.o users.o  

#executable filename
player: $(OBJ)
	g++ -o player $(OBJ)

command.o:	command.cpp command.h 
	g++ -c -std=c++11 command.cpp

follow.o: follow.cpp follow.h
	g++ -c -std=c++11 follow.cpp

followers.o: followers.cpp followers.h 
	g++ -c -std=c++11 followers.cpp

main.o:	main.cpp
	g++ -c main.cpp

mytunes.o:	mytunes.cpp mytunes.h UI.h
	g++ -c -std=c++11 mytunes.cpp

playlist.o: playlist.cpp playlist.h
	g++ -c -std=c++11 playlist.cpp

recording.o: recording.cpp recording.h 
	g++ -c -std=c++11 recording.cpp
	
recordings.o: recordings.cpp recordings.h 
	g++ -c -std=c++11 recordings.cpp

str_util.o:	str_util.cpp str_util.h 
	g++ -c -std=c++11 str_util.cpp

song.o: song.cpp song.h 
	g++ -c -std=c++11 song.cpp
	
songs.o: songs.cpp songs.h 
	g++ -c -std=c++11 songs.cpp

track.o: track.cpp track.h
	g++ -c -std=c++11 track.cpp
	
tracks.o: tracks.cpp tracks.h 
	g++ -c -std=c++11 tracks.cpp

UI.o:	UI.cpp UI.h 
	g++ -c -std=c++11 UI.cpp

user.o: user.cpp user.h 
	g++ -c -std=c++11 user.cpp
	
users.o: users.cpp users.h 
	g++ -c -std=c++11 users.cpp

clean:	
	find . -type f | xargs touch	
	rm -rf $(OBJ) player