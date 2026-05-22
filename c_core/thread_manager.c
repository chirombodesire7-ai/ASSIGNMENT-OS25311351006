#include <stdio.h>
#include <string.h>
#include "thread_manager.h"

void create_thread(Thread threads[], int *count, int pid, const char *name)
{
    threads[*count].tid = *count + 1;
    threads[*count].pid = pid;
    strcpy(threads[*count].name, name);
    threads[*count].state = 0;

    (*count)++;
}

void run_threads(Thread threads[], int count)
{
    printf("\nTHREAD EXECUTION\n\n");

    for (int i = 0; i < count; i++)
    {
        printf("Running Thread T%d (Process %d) - %s\n",
               threads[i].tid,
               threads[i].pid,
               threads[i].name);

        threads[i].state = 1;

        printf("Finished Thread T%d\n", threads[i].tid);
        threads[i].state = 2;
    }

    printf("\nALL THREADS COMPLETED\n");
}