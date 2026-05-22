#include <stdio.h>
#include "mutex_demo.h"

int counter = 0;

void run_mutex_demo()
{
    printf("\nMUTEX DEMO START\n\n");

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            counter++;
            printf("Thread %d -> counter: %d\n", i, counter);
        }
    }

    printf("\nMUTEX DEMO END\n");
}