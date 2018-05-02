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

OBJ = searchEngine.o 

#executable filename
search: $(OBJ)
	g++ -o search $(OBJ)

search.o: searchEngine.cpp  
	g++ -c -std=c++11 searchEngine.cpp

clean:	
	find . -type f | xargs touch	
	rm -rf $(OBJ) search