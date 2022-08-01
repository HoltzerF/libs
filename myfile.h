#ifndef MYFILE_H
#define MYFILE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* searches a file for an string starting at current file pointer
 * finally sets file pointer infront of string
 * returns 1 if string found, 0 if not
 * uses malloc
 */
int fsearch(FILE *fptr, char *str);

/* sets the file pointer to the start of a specific line
 * starting from beginning of file within line 1
 * returns 1 if line exist's, 0 if not
 */
int fline(FILE *fptr, int linenumber);

/* returns the filesize without changing the file pointer
 */
long fsize(FILE *fptr);

/* copies the content of a file into another file
 * for a specific size, from current file pointers
 */
void fcpy(FILE *a, FILE *b, long length);

/* prints a file from current file pointer to console
 */
void fprint(FILE *fptr);

/* replaces all strings in a file with another string
 *
 */
void freplace(FILE *a, FILE *b, char *search, char *replace);

#endif
