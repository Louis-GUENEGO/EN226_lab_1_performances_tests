#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdio.h>

#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <windows.h>
#else
#include <sys/time.h>
#endif

void StartTimer();
double GetTimer();

#endif
