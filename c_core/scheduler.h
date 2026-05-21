#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "include/eduos.h"

void fcfs_schedule(PCB processes[], int size);

void sjf_schedule(PCB processes[], int size);

void rr_schedule(
    PCB processes[],
    int size,
    int quantum
);

#endif