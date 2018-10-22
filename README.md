# MusicApp

/* * * * * * * * * * * * * * * * * * * * * * * * * * */
                                           
            Program:  Tuner Pro          
            Authors:                              
    
            (c) Syed Arsal Abbas

	    Freelance Work done for one of my clients 
	    Mr. Harshit Khurana
                                                     
/* * * * * * * * * * * * * * * * * * * * * * * * * * */


Instructions to execute the Program:
	
	I:

		1) 	The user will Compile the code using "make" command

		2) 	Once the user has compiled the program correctly, the system will generate an executable file called "player". Once the system successfully creates the exe file, user can run it on terminal using the command ./player

		3) 	Now that the user has started the program successfully, user should be able to execute all commands manually or run a script file to execute all commands.
			
			There are two script files included in the submission file:
				
				scriptFile.txt
				followScript.txt

			scriptFile.txt contain some add, delete and show commands. Once these files are opened in the terminal using a ".read 'filename' command, this will help the user to run these commands all at once rather then adding them line by line.

			followScript.txt contains some follow commands. This will test:
				-if application supports a command similar to:
					follow -u userid -p playlist_name -f userid2
				-if a command similar to:
					follow -u userid -playlist_name -f stop
				Should cause userid's playlist playlist_name to stop following changes of another user.
				-If changes are made to a playlist being followed then the changes should be reflected right away in playlists that are followers.
				-If implementation of the follow command is based on the Gamma Observer Pattern.
				-If the implementation uses the Subject and Observer abstract superclasses.

			Note: 
				We created these script files: "scriptFile.txt && followScript.txt" to check our "add", "show", "delete" and "follow" commands.

		5)	The user can also log the files using ".log" commands.
				More information is given about these commands in the ".help" menu of the program. 

		4)	The user can simply type ".quit" command to exit the program.

	II:

		PartII is basically an implementation of a search engine, given a proper set of input data. 

		instruction to compile and run:

			1) The user will Compile the code using: "make" command

			2) Once compiled, run it using the "./search.out" command

			3) The program will prompt you to enter the song name or a word contained in the song you want to search. Hit enter once you've added your input

			4) It will output all the relevant songs.
