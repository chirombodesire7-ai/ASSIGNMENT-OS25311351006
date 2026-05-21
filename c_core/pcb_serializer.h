#ifndef PCB_SERIALIZER_H
#define PCB_SERIALIZER_H

#include "eduos.h"

void export_snapshot(
    PCB processes[],
    int size,
    const char *algorithm
);

#endif