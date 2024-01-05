#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>



int main (int argc, char *argv[]){

	if (argc > 2) {
        	fprintf(stderr, "Error: Expected one argument, found %d\n", argc - 1);
        	return -1;
    	}else if( argc == 1){
		fprintf(stderr, "Error: Expected one argument, mone found\n");
                return -1;
	}

	int fd = open(argv[1], O_RDONLY);

	if(fd == -1) {
		printf("\nError Opening File!!\n");
	}

	int tot_chars = 0;
        int tot_lines = 0;
        int tot_words = 0;

	char current_char; //buffer
	int in_word = 0; //flag to track if inside a word

	while( read(fd, &current_char,sizeof(current_char))> 0){
		tot_chars++;

		if(isspace(current_char)){
			if(in_word){
				tot_words++;
				in_word = 0;
			}
			if(current_char == '\n'){
				tot_lines++;
			}

		} else {
			in_word = 1;
		}

		if(!isspace(current_char)){
			in_word =1;
		}



	}

	if (in_word) {
        	tot_words++;
		tot_lines++;
   	}

	close(fd);

	printf(" %d %d %d \n", tot_lines, tot_words, tot_chars);
	return 0;

}


