#include <stdio.h>
#include "pcb_serializer.h"

void export_processes_json(PCB processes[], int size, const char *filename){

    FILE *f = fopen(filename, "w");
    if (f == NULL)
{
    printf("File open error\n");
    return;
}

fprintf(f, "{\n");
fprintf(f, "  \"processes\": [\n");

for (int i = 0; i < size; i++)
{
    fprintf(f,
        "    {\"pid\": %d, \"name\": \"%s\", \"burst\": %d, \"wt\": %d, \"tat\": %d}%s\n",
        processes[i].pid,
        processes[i].name,
        processes[i].burst_time,
        processes[i].waiting_time,
        processes[i].turnaround_time,
        (i == size - 1) ? "" : ","
    );
}

fprintf(f, "  ]\n");
fprintf(f, "}\n");

fclose(f);

printf("JSON exported successfully: %s\n", filename);
}