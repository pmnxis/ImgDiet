#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//   VISUAL STUDIO stop! (instead of Ctrl + F5)
#if _MSC_VER >= 1600
#pragma warning(disable:4996)
#include <Windows.h>
#define BASH_STOP { printf("\n\n"); system("PAUSE");}
#else
#define STOP {}
#endif

#ifndef uint8_t
typedef unsigned char uint8_t;
#endif

#ifndef M_PI
#define M_PI 3.141592654
#endif


struct imgPot {
	int width;
	int height;
	uint8_t * data;
}typedef imgPot;

struct doublePot {
	int width;
	int height;
	double * data;
}typedef doublePot;

extern imgPot * Create_imgPot(const char filepath[], int w, int h);
extern uint8_t reviseUINT8(double input);
extern void Destroy_imgPot(imgPot * pot);
extern void Destroy_doublePot(doublePot * pot);
void store_ImgPot(imgPot * pot, const char filepath[]);