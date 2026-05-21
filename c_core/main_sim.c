#include <stdio.h>
#include "scheduler.h"
#include "pcb_serializer.h"

int main()
{
    int choice;

    PCB processes[4] =
    {
        {1, "Chrome", 6, 2, 0, 0, 0},
        {2, "VSCode", 3, 1, 0, 0, 0},
        {3, "Discord", 8, 3, 0, 0, 0},
        {4, "Spotify", 4, 2, 0, 0, 0}
    };

    printf("\nEDU OS SCHEDULER\n");
    printf("1. FCFS\n");
    printf("2. SJF\n");

    printf("Select option: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        fcfs_schedule(processes, 4);

        export_snapshot(
            processes,
            4,
            "FCFS"
        );
    }
    else if (choice == 2)
    {
        sjf_schedule(processes, 4);

        export_snapshot(
            processes,
            4,
            "SJF"
        );
    }
    else
    {
        printf("Invalid option\n");
    }

    return 0;
}