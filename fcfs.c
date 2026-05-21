#include <stdio.h>
#include "scheduler.h"
#include "logger.h"

void fcfs_schedule(PCB processes[], int size)
{
    log_event("FCFS scheduling started");

    int current_time = 0;

    float total_waiting = 0;
    float total_turnaround = 0;

    printf("\nFCFS EXECUTION ORDER\n\n");

    for (int i = 0; i < size; i++)
    {
        printf("P%d ", processes[i].pid);
    }

    printf("\n\nPROCESS RESULTS\n\n");

    for (int i = 0; i < size; i++)
    {
        processes[i].waiting_time = current_time;

        processes[i].turnaround_time =
            current_time + processes[i].burst_time;

        total_waiting += processes[i].waiting_time;

        total_turnaround +=
            processes[i].turnaround_time;

        printf(
            "PID: %d | WT: %d | TAT: %d\n",

            processes[i].pid,
            processes[i].waiting_time,
            processes[i].turnaround_time
        );

        current_time += processes[i].burst_time;
    }

    printf("\nAVERAGES\n\n");

    printf(
        "Average Waiting Time: %.2f\n",
        total_waiting / size
    );

    printf(
        "Average Turnaround Time: %.2f\n",
        total_turnaround / size
    );

    log_event("FCFS scheduling completed");
}