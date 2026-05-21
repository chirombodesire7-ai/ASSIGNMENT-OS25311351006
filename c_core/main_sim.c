#include <stdio.h>
#include "process_manager.h"

int main()
{
     PCB processes[3] = {
        {1, "P1", 5, 2, 0, 0, 0},
        {2, "P2", 3, 1, 0, 0, 0},
        {3, "P3", 8, 3, 0, 0, 0}


     };

   init_processes(processes, 3);

   print_processes(processes, 3);

   fcfs_schedule(processes, 3);

   return 0;
}