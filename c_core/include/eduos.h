#ifndef EDUOS_H
#define EDUOS_H

typedef struct {
int pid;
char name[50];
int burst_time;
int priority;
int arrival_time;
int waiting_time;
int turnaround_time;
} PCB;

#endif