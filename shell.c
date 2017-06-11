#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>/* defines types used by sys/stat.h */
#include <sys/stat.h>/* defines S_IREAD & S_IWRITE*/
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAXLINE 80 /* The maximum length command */
#define BUFFER_LEN 1024

int main(){
	// char * args[MAXLINE/2 + 1]; /* command line arguments */
	int shouldrun = 1; /* flag to determine when to exit program */

	char line[BUFFER_LEN];  //get command line
    char* argv[100];        //user command
    int argc;   

 //    int shmid;
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
	// current_dir = "";


	while (shouldrun) {
		printf("$bereket >> ");
		fflush(stdout);

		if(!fgets(line, BUFFER_LEN, stdin)){  //get command and put it in line
        	break;                                //if user hits CTRL+D break
	    }

	    if(strcmp(line, "exit\n")==0){            //check if command is exit
	        break;
	    }

	    char *token;
	    token = strtok(line," ");	//split command into separate strings
	    int i = 0;
	    while(token!=NULL){
	        argv[i]=token;      
	        token = strtok(NULL," ");
	        i++;
	    }
	    argv[i]=NULL;                     //set last value to NULL for execvp
		
	    argc=i;                           //get arg count
	    // for(i=0; i<argc; i++){
	    //     // printf("%s\n", argv[i]);      //print command/args
	    // }

	    int pid= fork();              //fork child

	    if(pid==0){               //Child
	        execv("/home/bereket/Second_Semister_OS/Project_shell/e",argv);
	        fprintf(stderr, "Child process could not do execv\n");

	    }else{                    //Parent
	    	if(strcmp(argv[argc-1], "&\n")) // not &
	        {wait(NULL);}
	        
	    }

	}
	return 0 ;
}