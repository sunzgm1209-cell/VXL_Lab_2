/*
 * software_timer.h
 *
 *  Created on: Sep 21, 2026
 *      Author: ASUS
 */

#ifndef SOFTWARE_TIMER_H
#define SOFTWARE_TIMER_H

#include <stdint.h>

#define MAX_TIMERS 10
#define TIMER_CYCLE 10

extern int timer_flags[MAX_TIMERS];

void initTimers(void);
int requestTimer(void);
void setTimer(int id, int duration);
void timer_run(void);
void freeTimer(int id);

#endif /* SOFTWARE_TIMER_H_ */
