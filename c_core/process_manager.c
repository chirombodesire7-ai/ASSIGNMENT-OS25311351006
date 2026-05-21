#include <stdio.h>
#include "process_manager.h"

void display_processes(PCB processes[], int n)
{
    printf("\nPROCESS LIST\n\n");

    for (int i = 0; i < n; i++)
    {
        printf(
            "PID: %d | NAME: %s | BURST: %d\n",
            processes[i].pid,
            processes[i].name,
            processes[i].burst_time
        );
    }
}

void calculate_averages(PCB processes[], int n)
{
    float total_wt = 0;
    float total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        total_wt += processes[i].waiting_time;
        total_tat += processes[i].turnaround_time;
    }

    printf("\nAVERAGES\n\n");

    printf(
        "Average Waiting Time: %.2f\n",
        total_wt / n
    );

    printf(
        "Average Turnaround Time: %.2f\n",
        total_tat / n
    );
}