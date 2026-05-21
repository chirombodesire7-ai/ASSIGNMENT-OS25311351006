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

void export_fcfs_snapshot(PCB processes[], int size){
    FILE *f = fopen("pcb_snapshot.json", "w");
    if (f == NULL)
{
    printf("Failed to create snapshot file\n");
    return;
}

fprintf(f, "{\n  \"fcfs_snapshot\": [\n");

for (int i = 0; i < size; i++)
{
    fprintf(f,
        "    {\"pid\": %d, \"wt\": %d, \"tat\": %d}%s\n",
        processes[i].pid,
        processes[i].waiting_time,
        processes[i].turnaround_time,
        (i == size - 1) ? "" : ","
    );
}

fprintf(f, "  ]\n}\n");

fclose(f);

printf("\nSnapshot saved to pcb_snapshot.json\n");
}