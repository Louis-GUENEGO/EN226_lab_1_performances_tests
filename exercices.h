#ifndef __EXERCICES_H__
#define __EXERCICES_H__

#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "timer.h"

#define FALSE 0
#define TRUE  1

extern FILE * pPerf1;
extern FILE * pPerf2;

void Go1( unsigned int count, unsigned int stride );
void Go2( unsigned int steps, unsigned int arrSize, unsigned int clSize );
void Go3();
void Go4();
void Go5();
void Go6();

#endif
