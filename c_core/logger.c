#include <stdio.h>
#include <time.h>
#include "logger.h"

void log_event(const char *message)
{
    FILE *f = fopen("../logs/eduos.log", "a");

    if (f == NULL)
    {
        printf("Log file error\n");
        return;
    }

    time_t now = time(NULL);

    fprintf(f, "[%ld] %s\n", now, message);

    fclose(f);
}