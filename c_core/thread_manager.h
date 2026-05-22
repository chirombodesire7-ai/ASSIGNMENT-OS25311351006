#ifndef THREAD_MANAGER_H
#define THREAD_MANAGER_H

typedef struct
{
    int tid;
    int pid;
    char name[50];
    int state;   // 0 = ready, 1 = running, 2 = finished
} Thread;

void create_thread(Thread threads[], int *count, int pid, const char *name);
void run_threads(Thread threads[], int count);

#endif