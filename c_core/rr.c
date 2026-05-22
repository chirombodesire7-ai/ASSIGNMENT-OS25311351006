#include <stdio.h>
#include "process_manager.h"

void rr_schedule(PCB processes[], int n, int quantum)
{
    int remaining[10];
    int completion_time[10];
    int first_response[10];
    int visited[10];

    int time = 0;
    int completed = 0;

    for (int i = 0; i < n; i++)
    {
        remaining[i] = processes[i].burst_time;
        completion_time[i] = 0;
        first_response[i] = -1;
        visited[i] = 0;

        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("\nROUND ROBIN EXECUTION\n\n");

    while (completed < n)
    {
        int progress = 0;

        for (int i = 0; i < n; i++)
        {
            if (remaining[i] > 0)
            {
                progress = 1;

                printf("P%d ", processes[i].pid);

                if (first_response[i] == -1)
                {
                    first_response[i] = time;
                }

                if (remaining[i] > quantum)
                {
                    time += quantum;
                    remaining[i] -= quantum;
                }
                else
                {
                    time += remaining[i];
                    remaining[i] = 0;

                    completion_time[i] = time;

                    completed++;
                }
            }
        }

        if (progress == 0)
        {
            break;
        }
    }

    printf("\n\nPROCESS RESULTS\n\n");

    float total_wt = 0;
    float total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        processes[i].turnaround_time = completion_time[i];
        processes[i].waiting_time =
            completion_time[i] - processes[i].burst_time;

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

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}