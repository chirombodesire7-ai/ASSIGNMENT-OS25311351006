#include <stdio.h>
#include "process_manager.h"

void init_processes(PCB processes[], int size)
{

  for (int i = 0; i < size; i++){
    processes[i].waiting_time = 0;
    processes[i].turnaround_time = 0;

  }

}


void print_processes(PCB processes[], int size){
     for (int i = 0; i < size; i++){
        printf("PID %d | %s | BT %d | PR %d\n",
        processes[i].pid,
        processes[i].name,
        processes[i].burst_time,
        processes[i].priority
        );
     }

}

void fcfs_schedule(PCB processes[], int size) {
    int total_time = 0;

    for (int i = 0; i < size; i++) {
        processes[i].waiting_time = total_time;
        total_time += processes[i].burst_time;
        processes[i].turnaround_time = total_time;
    }

    printf("\n\nDetails:\n");

    for (int i = 0; i < size; i++){
        processes[i].waiting_time = current_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        printf("PID %d | WT %d | TAT %d\n",
        processes[i].pid,
        processes[i].waiting_time,
        processes[i].turnaround_time
    );

        current_time += processes[i].burst_time;
    }
}
