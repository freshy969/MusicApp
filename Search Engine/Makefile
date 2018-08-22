#=============================
#
#	Code Written by:
#    
#   Syed Arsal Abbas
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