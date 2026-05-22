#include <stdio.h>


int shared_counter = 0;

void process_write(int id)
{
    int temp = shared_counter;
    printf("Process P%d reads %d\n", id, temp);

    temp = temp + 1;

    shared_counter = temp;

    printf("Process P%d writes %d\n", id, shared_counter);
}

void shared_memory_demo()
{
    printf("\nSHARED MEMORY DEMO\n\n");

    shared_counter = 0;

    for (int i = 1; i <= 3; i++)
    {
        process_write(i);
    }

    printf("\nFinal shared value: %d\n", shared_counter);
}