#ifndef SSTRING_H
#define SSTRING_H

int c2i_s(char c);
int strlen_s(char *s, int b_size);
int strcpy_s(char *dest, char *src, int b_size);
void strcat_s(char *dest, char *src, int b_size);
char *strchr_s(char *str, char c, int b_size);
char *strbrk_s(char *str, char *tok, int b_size);
int streql_s(char *s0, char *s1, int b_size);
int cpyasc_s(char* dest, char* src, int b_size);
void strrev_s(char *str);

#endif
