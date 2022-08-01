#ifndef CSCREEN_H
#define CSCREEN_H

#include <stdio.h>

// set console width
#ifndef WIDTH
#define WIDTH 120
#endif

// set console height
#ifndef HEIGHT
#define HEIGHT 30
#endif

// the screen buffer
char cbScreen[WIDTH * HEIGHT];

// clears the screen buffer to a specific char
void cbClear(char c);

// flushes the screen buffer to the console
void cbFlush();

// initialize consoleBuffer and clears console
void cbInit();

// draws a specific pixel into the screen buffer
void cbPixel(int x, int y, char c);

// draws a string into the screen buffer
void cbString(int x, int y, char *s);

#endif
