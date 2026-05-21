#include <stdio.h>
#include "process_manager.h"

int main()
{
    PCB processes[4] =
    {
        {1, "Chrome", 5, 2, 0, 0, 0},
        {2, "VSCode", 3, 1, 0, 0, 0},
        {3, "Discord", 8, 3, 0, 0, 0},
        {4, "Spotify", 4, 2, 0, 0, 0}
    };

    init_processes(processes, 4);

    print_processes(processes, 4);

    fcfs_schedule(processes, 4);
    
    sjf_schedule(processes, 4);

    return 0;
}