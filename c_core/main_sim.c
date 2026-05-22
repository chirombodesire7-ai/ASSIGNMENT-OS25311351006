#include <stdio.h>
#include "scheduler.h"
#include "pcb_serializer.h"
#include "thread_manager.h"
#include "ipc_module.h"
#include "deadlock_demo.h"
#include "shared_memory.h"
#include "mutex_demo.h"

int main()
{
    int choice = -1;
    int quantum = 2;

    PCB base_processes[4] =
    {
        {1, "Chrome", 6, 2, 0, 0, 0},
        {2, "VSCode", 3, 1, 0, 0, 0},
        {3, "Discord", 8, 3, 0, 0, 0},
        {4, "Spotify", 4, 2, 0, 0, 0}
    };

    while (choice != 0)
    {
        PCB processes[4];

        for (int i = 0; i < 4; i++)
        {
            processes[i] = base_processes[i];
        }

        printf("\n============================\n");
        printf("      EDU OS SCHEDULER\n");
        printf("============================\n");

        printf("1. FCFS\n");
        printf("2. SJF\n");
        printf("3. ROUND ROBIN\n");
        printf("4. PRIORITY\n");
        printf("5. THREADS\n");
        printf("6. IPC (Producer Consumer)\n");
        printf("7. DEADLOCK DETECTION\n");
        printf("8. SHARED MEMORY\n");
        printf("9. MUTEX DEMO\n");
        printf("0. EXIT\n");

        printf("\nSelect option: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            fcfs_schedule(processes, 4);
            export_snapshot(processes, 4, "FCFS");
        }
        else if (choice == 2)
        {
            sjf_schedule(processes, 4);
            export_snapshot(processes, 4, "SJF");
        }
        else if (choice == 3)
        {
            printf("Enter Quantum: ");
            scanf("%d", &quantum);

            rr_schedule(processes, 4, quantum);
            export_snapshot(processes, 4, "ROUND_ROBIN");
        }
        else if (choice == 4)
        {
            priority_schedule(processes, 4);
            export_snapshot(processes, 4, "PRIORITY");
        }
        else if (choice == 5)
        {
            Thread threads[10];
            int count = 0;

            create_thread(threads, &count, 1, "Chrome Thread");
            create_thread(threads, &count, 2, "VSCode Thread");
            create_thread(threads, &count, 3, "Discord Thread");

            run_threads(threads, count);
        }
        else if (choice == 6)
        {
            int sub, item;

            printf("\nIPC MENU\n");
            printf("1. Produce\n");
            printf("2. Consume\n");
            printf("3. Show Buffer\n");

            printf("Select IPC option: ");
            scanf("%d", &sub);

            if (sub == 1)
            {
                printf("Enter item: ");
                scanf("%d", &item);
                producer(item);
            }
            else if (sub == 2)
            {
                consumer();
            }
            else if (sub == 3)
            {
                show_buffer();
            }
        }
        else if (choice == 7)
        {
            detect_deadlock();
        }
        else if (choice == 8)
        {
            shared_memory_demo();
        }
        else if (choice == 9)
        {
            run_mutex_demo();
        }
        else if (choice == 0)
        {
            printf("\nExiting EDU OS...\n");
        }
        else
        {
            printf("Invalid option\n");
        }
    }

    return 0;
}