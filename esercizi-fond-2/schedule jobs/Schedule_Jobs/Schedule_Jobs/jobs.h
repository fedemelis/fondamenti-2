#pragma once
#include <stdlib.h>

typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

extern int ScheduleJobs(const job* jobs, size_t j_size);