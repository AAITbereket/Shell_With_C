#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>/* defines types used by sys/stat.h */
#include <sys/stat.h>/* defines S_IREAD & S_IWRITE*/
#include <fcntl.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>

#define MAXLINE 80 /* The maximum length command */
#define BUFFER_LEN 1024

int main(int argc,char *argv[],char *envp[]){

	// int shmid;
	// key_t key;
	// char *current_dir;
	// key = 5678;
	// if ((shmid = shmget(key, 27, IPC_CREAT | 0666)) < 0) {
	// 	printf("shmget error");
	// 	exit(1);
	// }

	// if ((current_dir = shmat(shmid, NULL, 0)) == (char *) -1) {
	// 	printf("shmat error");
	// 	exit(1);
	// }
	

	if (argc > 0){

	    if (!strcmp(argv[0],"cf") && argc > 1)
	    {
	    	creat(argv[1], S_IREAD | S_IWRITE);
	    }
	    else if(!strcmp(argv[0],"cpf"))
	    {
	    	ssize_t nr; int fd; char *buf;

	    	char *src = argv[1];
	    	char *dest = argv[2];

	    	if( access( src, F_OK ) == -1 ) {
				printf("\n Error: File doesn't exist \n");
				exit(0);
				}

	    	fd = open (src,O_RDWR);
			nr = read (fd, buf, 11);

			if (nr == -1)
				{printf("\n\tThere was an error reading the file --\n"); exit(0);}
			close(fd);

			if(!strcmp(argv[argc-1], "-a\n")){
				printf("append mode \n");
				fd = open (dest, O_RDWR | O_APPEND);
			}
			else{
				fd = creat (dest, 0644);	
			}

			nr = write (fd, buf, strlen (buf));
			
			if (nr == -1)
				{printf("\n\tThere was an error writing to the file\n");
				 exit(0);
				}

	    }
	    else if(!strcmp(argv[0],"display"))
	    {
	 		execv("/home/bereket/Second_Semister_OS/Project_shell/display",argv);

	    }
	    else if(!strcmp(argv[0],"ctdir"))
	    {
	    	printf("Creating direcrory \n");
	    	mkdir(argv[1],0755);
	    	mkdir("what", 0755);
	    }
	    else if(!strcmp(argv[0],"chgdir"))
	    {
	  //   	printf("help \n");
	  //   	// execv("/home/bereket/Second_Semister_OS/Project_shell/chgdir",argv);
	  //   	if (chdir(argv[2]) == 1)
			// {
			//     printf("Failed to change directory");
			// }
			// printf("%d",chgdir(argv[2]));
	    }
	    else if(!strcmp(argv[0],"pslist"))
	    {
	    	printf("ps list called \n");
	    	system("cd pslist");
	    	system("dmesg");
	    }
	    else if(!strcmp(argv[0],"hlp"))
	    {

	    	if(argc == 2){
	    		printf("Here are all list of commands \n");
	    		printf("\t ctdir ----  is used to create directory and sub directory \n");
	    		printf("\t chgdir ---- is used to change current directory \n");
	    		printf("\t pslist ----- is used to list all process ids and parent process \n");
	    		printf("\t cf ---- is used to create a new file \n");
	    		printf("\t cpf ---- is used to copy file \n");
	    		printf("\t display ---- is used display content of a file \n");

	    	}
	    	else if(!strcmp(argv[1],"ctdir"))
		    {
		    	printf("--------------        ctdir help        ---------------- \n");
		    	printf("\n");
		    	printf("This command is used to create directory and sub directory \n");
		    	printf(" \t \t usage: ctdir foo  \n");
		    	printf(" \t \t usage: ctdir foo/bar  \n");
		    }
		    else if(!strcmp(argv[1],"chgdir"))
		    {
		    	printf("--------------        chgdir help        ---------------- \n");
		    	printf("\n");
		    	printf("This command is used to change current directory \n");
		    	printf(" \t \t usage: chgdir foo  \n");
		    	printf(" \t \t usage: ctdir foo/bar  \n");
		    }
		    else if(!strcmp(argv[1],"pslist"))
		    {
		    		printf("--------------        pslist help        ---------------- \n");
			    	printf("\n");
			    	printf("This command is used to list all process ids and parent process \n");
			    	printf(" \t \t usage: pslist  \n");
		    }
		    else if(!strcmp(argv[1],"cf"))
		    {
		    		printf("--------------        create file help        ---------------- \n");
			    	printf("\n");
			    	printf("This command is used to create a new file \n");
			    	printf(" \t \t usage: cf foo   \n");
			    	printf(" \t \t usage: cf foo/bar  \n");
		    }
		    else if(!strcmp(argv[1],"cpf"))
		    {
		    		printf("--------------        cpf help        ---------------- \n");
			    	printf("\n");
			    	printf("This command is used to copy a file \n");
			    	printf(" \t \t usage: cpf source_file destiation file   \n");
			    	printf(" \t \t usage: cpf source_file destiation file  -a   for append mode \n");
		    }
		    else if(!strcmp(argv[1],"display"))
		    {
		    		printf("--------------        display help        ---------------- \n");
			    	printf("\n");
			    	printf("This command is used display content of a file \n");
			    	printf(" \t \t usage: display foo.txt   \n");
			    	printf(" \t \t usage: display foo/bar.txt   \n");
		    }
		    else
		    {
			    	printf(" \t No command with a name %s \n", argv[1] );
			    	
		    }
	    }
	    else if(!strcmp(argv[0],"clear")){
	    	system("clear");	
	    }
	    else {
	    	printf("\t Command is unkown. Type hlp command to see the list of command \n");
	    }

	}
	return 0 ;
}