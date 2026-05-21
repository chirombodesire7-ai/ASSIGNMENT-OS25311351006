#include <stdio.h>
#include "process_manager.h"

void init_processes(PCB processes[], int size)
{
    for (int i = 0; i < size; i++)
    {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}

void print_processes(PCB processes[], int size)
{
    printf("\nPROCESS LIST\n\n");

    for (int i = 0; i < size; i++)
    {
        printf(
            "PID: %d | NAME: %s | BT: %d | PRIORITY: %d\n",
            processes[i].pid,
            processes[i].name,
            processes[i].burst_time,
            processes[i].priority
        );
    }
}

void fcfs_schedule(PCB processes[], int size)
{
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
            processes[i].waiting_time +
            processes[i].burst_time;

        total_waiting += processes[i].waiting_time;
        total_turnaround += processes[i].turnaround_time;

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
}

void sjf_schedule(PCB processes[], int size){

    PCB temp;
    int i, j;

    printf("\nSJF SCHEDULING\n");

for (i = 0; i < size - 1; i++)
{
    for (j = i + 1; j < size; j++)
    {
        if (processes[i].burst_time > processes[j].burst_time)
        {
            temp = processes[i];
            processes[i] = processes[j];
            processes[j] = temp;
        }
    }
}

int current_time = 0;
float total_waiting = 0;
float total_turnaround = 0;

printf("Order: ");

for (i = 0; i < size; i++)
{
    printf("P%d ", processes[i].pid);
}

printf("\n\nResults:\n");

for (i = 0; i < size; i++)
{
    processes[i].waiting_time = current_time;
    processes[i].turnaround_time = current_time + processes[i].burst_time;

    total_waiting += processes[i].waiting_time;
    total_turnaround += processes[i].turnaround_time;

    printf("PID %d | WT %d | TAT %d\n",
        processes[i].pid,
        processes[i].waiting_time,
        processes[i].turnaround_time
    );

    current_time += processes[i].burst_time;
}

printf("\nAverage WT: %.2f\n", total_waiting / size);
printf("Average TAT: %.2f\n", total_turnaround / size);
}