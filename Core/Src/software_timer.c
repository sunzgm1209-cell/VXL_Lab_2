/*
 * software_timer.c
 *
 *  Created on: Sep 21, 2026
 *      Author: ASUS
 */
#include "software_timer.h"

int timer_flags[MAX_TIMERS];
int timer_counters[MAX_TIMERS];
int timer_allocated[MAX_TIMERS];

void initTimers(void) {
    for (int i = 0; i < MAX_TIMERS; ++i) {
        timer_flags[i] = 0;
        timer_counters[i] = 0;
        timer_allocated[i] = 0;
    }
}

 int requestTimer(void){
	 for (int i = 0; i < MAX_TIMERS; ++i){
		 if (timer_allocated[i] == 0){
			 timer_allocated[i] = 1;
			 return i;
		 }
	 }

	 return -1;
 }

 void setTimer(int id, int duration){
	 if (id >= 0 && id < MAX_TIMERS){
		 timer_counters[id] = duration / TIMER_CYCLE;
		 timer_flags[id] = 0;
	 }
 }

 void timerRun(void){
	 for (int i = 0; i < MAX_TIMERS; ++i){
		 if (timer_allocated[i] == 1 && timer_counters[i] > 0){
			 timer_counters[i]--;
			 if (timer_counters[i] <= 0){
				 timer_flags[i] = 1;
			 }
		 }
	 }
 }

 void freeTimer(int id){
	 if (id >= 0 && id < MAX_TIMERS){
		 timer_allocated[id] = 0;
		 timer_counters[id] = 0;
		 timer_flags[id] = 0;
	 }
 }
