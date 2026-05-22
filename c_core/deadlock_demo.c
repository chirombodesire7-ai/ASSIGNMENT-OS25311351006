#include <stdio.h>


void detect_deadlock()
{
    int process1_waiting = 1;
    int process2_waiting = 1;

    printf("\nDEADLOCK SIMULATION\n\n");

    printf("Process P1 holds Resource R1\n");
    printf("Process P1 waits for Resource R2\n\n");

    printf("Process P2 holds Resource R2\n");
    printf("Process P2 waits for Resource R1\n\n");

    if (process1_waiting && process2_waiting)
    {
        printf("DEADLOCK DETECTED\n");
    }
    else
    {
        printf("NO DEADLOCK\n");
    }
}