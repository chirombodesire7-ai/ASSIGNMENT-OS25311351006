#include <stdio.h>
#include "logger.h"

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;

void producer(int item)
{
    if (count == BUFFER_SIZE)
    {
        printf("Buffer full. Producer waits\n");
        return;
    }

    buffer[in] = item;

    printf("Produced: %d at %d\n", item, in);

    in = (in + 1) % BUFFER_SIZE;
    count++;

    log_event("Producer added item");
}

void consumer()
{
    if (count == 0)
    {
        printf("Buffer empty. Consumer waits\n");
        return;
    }

    int item = buffer[out];

    printf("Consumed: %d from %d\n", item, out);

    out = (out + 1) % BUFFER_SIZE;
    count--;

    log_event("Consumer removed item");
}

void show_buffer()
{
    printf("\nBUFFER STATE:\n");

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("[%d] ", buffer[i]);
    }

    printf("\n");
}