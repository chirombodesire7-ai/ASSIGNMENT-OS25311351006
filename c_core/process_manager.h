#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include "eduos.h"

void init_processes(PCB processes[], int size);

void print_processes(PCB processes[], int size);

void fcfs_schedule(PCB processes[], int size);
void sjf_schedule(PCB processes[], int size);
void rr_schedule(PCB processes[], int size, int quantum);
void export_fcfs_snapshot(PCB processes[], int size);
#endif