#ifndef MYFILE_H
#define MYFILE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* prints a file from current file pointer to console
 */
void fprint(FILE *fptr);

/* returns the filesize without changing the file pointer
 */
long fsize(FILE *fptr);

/* copies the content of a file into another file
 * for a specific length, from current file pointers
 */
void fcpy(FILE *a, FILE *b, long length);

/* counts the appearance of the symbol sym infront of the file pointer
 */
long fcount(FILE *fptr, int sym);

/* searches a file for an string starting at current file pointer
 * finally sets file pointer infront of string
 * returns 1 if string found, 0 if not
 * uses malloc
 */
int fsearch(FILE *fptr, char *str);

/* return the current line the file pointer is at,
 * starting with 1
 */
long flinenum(FILE *fptr);

/* sets the file pointer to the start of a specific line
 * starting from beginning of file with line 1
 * returns 1 if line exist's, 0 if not
 */
int fline(FILE *fptr, int linenumber);

/* jumps to the beginning of the current line
 */
void flinestart(FILE *fptr);

/* returns the size of the current line
 * (linestart to end)
 */
long flinesize(FILE *fptr);

#endif
