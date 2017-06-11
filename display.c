#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[],char *envp[]){
	 


	 if(argc > 1){

	    	ssize_t nr_; int fd_; char *buf_;

	    	char *file_  = argv[1];

	    	fd_ = open (file_, O_RDONLY);
			nr_ = read (fd_, buf_, 120);

			if (nr_ == -1)
				printf("\n\n\tThere was an error reading the file\n");

			printf(buf_);
			printf("\n");
		}
	return 0;
}
