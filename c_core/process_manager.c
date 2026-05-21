#include <stdio.h>
#include "process_manager.h"
#include "logger.h"

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



void rr_schedule(PCB processes[], int size, int quantum){

    int remaining[size];
    int i;

    printf("\nROUND ROBIN SCHEDULING\n");

for (i = 0; i < size; i++)
{
    remaining[i] = processes[i].burst_time;
}

int current_time = 0;
int done;

do
{
    done = 1;

    for (i = 0; i < size; i++)
    {
        if (remaining[i] > 0)
        {
            done = 0;

            if (remaining[i] > quantum)
            {
                current_time += quantum;
                remaining[i] -= quantum;
            }
            else
            {
                current_time += remaining[i];
                processes[i].turnaround_time = current_time;
                processes[i].waiting_time =
                    processes[i].turnaround_time - processes[i].burst_time;

                remaining[i] = 0;
            }
        }
    }
}
while (!done);

printf("\nResults:\n");

float total_wt = 0;
float total_tat = 0;

for (i = 0; i < size; i++)
{
    total_wt += processes[i].waiting_time;
    total_tat += processes[i].turnaround_time;

    printf("PID %d | WT %d | TAT %d\n",
        processes[i].pid,
        processes[i].waiting_time,
        processes[i].turnaround_time
    );
}

printf("\nAverage WT: %.2f\n", total_wt / size);
printf("Average TAT: %.2f\n", total_tat / size);

}

