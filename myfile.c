#include "myfile.h"

void fprint(FILE *fptr){
	
	// prints every character of file until end of file
	int c;
	while((c = fgetc(fptr)) != EOF){
		putchar(c);
	}
}

long fsize(FILE *fptr){
	
	// saving file pointer
	long curr = ftell(fptr);
	
	// getting filesize
	fseek(fptr, 0, SEEK_END);
	long size = ftell(fptr);
	
	// restoring file pointer and return
	fseek(fptr, curr, SEEK_SET);
	return size;
}

void fcpy(FILE *a, FILE *b, long length){
	
	// copies characters until length or end of file
	int c;
	long i = 0;
	while((c = fgetc(a)) != EOF && i++ < length){
		fputc(c, b);
	}
}

long fcount(FILE *fptr, int sym){
	
	// getting current file pointer and setting file pointer to beginning of file
	long curr = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);
	
	// go through file until we hit file pointer, count the occurence of sym
	long count = 0;
	int c;
	while((c = fgetc(fptr)) != EOF && curr--){
		if(c == sym){
			++count;
		}
	}
	
	// restore file pointer and return result
	fseek(fptr, curr, SEEK_SET);
	return count;
}

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

long flinenum(FILE *fptr){
	return fcount(fptr, '\n') + 1;
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

void flinestart(FILE *fptr){
	long line = flinenum(fptr);
	fline(fptr, line);
}

long flinesize(FILE *fptr){
	
	// save current file pointer
	long curr = ftell(fptr);
	
	// current line we are in
	long line = flinenum(fptr);
	
	// getting line start and line end
	flinestart(fptr);
	long start = ftell(fptr);
	
	fline(fptr, line + 1);
	long end = ftell(fptr);
	
	// restore file pointer and return difference
	fseek(fptr, curr, SEEK_SET);
	return end - start;
}
