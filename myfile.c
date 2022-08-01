#include "myfile.h"

int fsearch(FILE *fptr, char *str){
	
	// allocate memory to hold null terminated string stored in str
	int len = strlen(str);
	char *buff = malloc(len + 1);
	if(buff == 0){
		return 0;
	}
	
	// search through the file for beginning character of str
	while((buff[0] = fgetc(fptr)) != EOF){
		
		// found
		if(buff[0] == *str){
			
			// save file pointer
			long pos = ftell(fptr);
			
			// read the next chars and null terminate the buffer
			if(fread(buff + 1, len - 1, 1, fptr) == 0){
				return 0; // we are at the end of the file
			}
			buff[len] = 0;
			
			// checks for equality with search string
			if(strcmp(buff, str) == 0){
				fseek(fptr, pos - 1, SEEK_SET);	// repositioning of file pointer and exit
				free(buff);
				return 1;
			}
		}
	}
	
	// file doesnt contain beginning character of str, so clean and return
	free(buff);
	return 0;
}

int fline(FILE *fptr, int linenumber){
	
	// sets the filepointer to beginning of file
	fseek(fptr, 0, SEEK_SET);
	
	// counts the newlines until we hit linenumber
	char c;
	int i = 1;
	while((c = fgetc(fptr)) != EOF){
		if(c == '\n'){
			if(++i == linenumber){
				return 1;
			}
		}
	}
	return 0;
}

long fsize(FILE *fptr){
	
	// saving file pointer
	long tmp = ftell(fptr);
	
	// getting filesize
	fseek(fptr, 0, SEEK_END);
	long size = ftell(fptr);
	
	// restoring file pointer and return
	fseek(fptr, tmp, SEEK_SET);
	return size;
}

void fcpy(FILE *a, FILE *b, long length){
	char c;
	long i = 0;
	while((c = fgetc(a)) != EOF && i++ < length){
		fputc(c, b);
	}
}

void fprint(FILE *fptr){
	char c;
	while((c = fgetc(fptr)) != EOF){
		putchar(c);
	}
}

void freplace(FILE *a, FILE *b, char *search, char *replace){
	fseek(a, 0, SEEK_SET);
	fseek(b, 0, SEEK_SET);
	/*
	while(fsearch(a, search)){
		fcpy(a, )
	}*/
}
