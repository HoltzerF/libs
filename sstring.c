#include "sstring.h"

int c2i_s(char c){
	return c - '0';
}

int strlen_s(char *s, int b_size){
	int i;
	for(i = 0; i < b_size; ++i)
		if(s[i] == '\0')
    		break;
	return i;
}

int strcpy_s(char *dest, char *src, int b_size){
	int i;
	for(i = 1; *src && i < b_size; ++i)
		*dest++ = *src++;
		
	*dest = '\0';
	return i - 1;
}

void strcat_s(char *dest, char *src, int b_size){
	
	int len = strlen_s(dest, b_size);
	char *ptr = dest + len;
	
	while(*src != '\0' && ++len < b_size)
		*ptr++ = *src++;
		
	*ptr = '\0';
}

char *strchr_s(char *str, char c, int b_size){
	int i = 0;
	while(*str != 0 && ++i < b_size){
		if(*str == c)
			return str;
		str++;
	}
	return 0;
}

char *strbrk_s(char *str, char *tok, int b_size){
	int i = 0;
	char *ptr = str;
	while(*ptr != 0 && i++ < b_size - 1){
		char *tmp = tok;
		while(*tmp != 0){
			if(*tmp++ == *ptr){
				return ptr;
			}
		}
		++ptr;
	}
	return 0;
}

int streql_s(char *s0, char *s1, int b_size){
	int i;
	for(i = 0; *s0 == *s1 && i < b_size - 1; ++s0, ++s1, ++i){
		if(s0 == '\0'){
			return 0;
		}
	}
	return 1;
}

int cpyasc_s(char* dest, char* src, int b_size){
    int i;
	for(i = 0, --b_size; i < b_size && (*src); ++i){
		if(*src >= 32 && *src <= 126){
			*dest++ = *src++;
		}else{
			*dest++ = ' ';
			src++;
		}
	}
	*dest = '\0';
	return i;
}

void strrev_s(char *str){
	char *beg = str;
	char *end = str;
	
	while(*end != 0){
		++end;
	}
	--end;
	
	while(beg < end){
		char temp = *end;
		*end-- = *beg;
		*beg++ = temp;
	}
}
