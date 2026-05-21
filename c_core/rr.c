#include <stdio.h>
#include "process_manager.h"

void rr_schedule(PCB processes[], int n, int quantum)
{
    int remaining[10];
    int time = 0;
    int completed = 0;

    for (int i = 0; i < n; i++)
    {
        remaining[i] = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("\nROUND ROBIN EXECUTION\n\n");

    while (completed < n)
    {
        int done = 1;

        for (int i = 0; i < n; i++)
        {
            if (remaining[i] > 0)
            {
                done = 0;

                printf("P%d ", processes[i].pid);

                if (remaining[i] > quantum)
                {
                    time += quantum;
                    remaining[i] -= quantum;
                }
                else
                {
                    time += remaining[i];

                    processes[i].turnaround_time = time;

                    processes[i].waiting_time =
                        time - processes[i].burst_time;

                    remaining[i] = 0;

                    completed++;
                }
            }
        }

        if (done)
        {
            break;
        }
    }

    printf("\n\nPROCESS RESULTS\n\n");

    float total_wt = 0;
    float total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        total_wt += processes[i].waiting_time;
        total_tat += processes[i].turnaround_time;

        printf(
            "PID: %d | WT: %d | TAT: %d\n",
            processes[i].pid,
            processes[i].waiting_time,
            processes[i].turnaround_time
        );
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