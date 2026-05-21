#include <stdio.h>
#include "scheduler.h"
#include "logger.h"

void rr_schedule(
    PCB processes[],
    int size,
    int quantum
)
{
    log_event("Round Robin scheduling started");

    int remaining[size];

    int current_time = 0;

    int completed = 0;

    float total_waiting = 0;
    float total_turnaround = 0;

    for (int i = 0; i < size; i++)
    {
        remaining[i] =
            processes[i].burst_time;
    }

    printf("\nROUND ROBIN EXECUTION\n\n");

    while (completed < size)
    {
        for (int i = 0; i < size; i++)
        {
            if (remaining[i] > 0)
            {
                printf("P%d ", processes[i].pid);

                if (remaining[i] > quantum)
                {
                    current_time += quantum;

                    remaining[i] -= quantum;
                }
                else
                {
                    current_time += remaining[i];

                    processes[i].turnaround_time =
                        current_time;

                    processes[i].waiting_time =
                        current_time -
                        processes[i].burst_time;

                    total_waiting +=
                        processes[i].waiting_time;

                    total_turnaround +=
                        processes[i].turnaround_time;

                    remaining[i] = 0;

                    completed++;
                }
            }
        }
    }

    printf("\n\nPROCESS RESULTS\n\n");

    for (int i = 0; i < size; i++)
    {
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
        total_waiting / size
    );

    printf(
        "Average Turnaround Time: %.2f\n",
        total_turnaround / size
    );

    log_event(
        "Round Robin scheduling completed"
    );
}