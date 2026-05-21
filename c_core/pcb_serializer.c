#include <stdio.h>
#include "pcb_serializer.h"

void export_snapshot(
    PCB processes[],
    int size,
    const char *algorithm
)
{
    FILE *f = fopen("pcb_snapshot.json", "w");

    if (f == NULL)
    {
        printf("Snapshot file error\n");
        return;
    }

    fprintf(f, "{\n");
    fprintf(f, "  \"algorithm\": \"%s\",\n", algorithm);
    fprintf(f, "  \"processes\": [\n");

    for (int i = 0; i < size; i++)
    {
        fprintf(
            f,
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

    printf("\nSnapshot exported successfully\n");
}