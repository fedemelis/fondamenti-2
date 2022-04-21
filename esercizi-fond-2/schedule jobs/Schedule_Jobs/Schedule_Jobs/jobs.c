#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

static int ScheduleJobsRec(const job* jobs, size_t j_size, int *appet, int* used, int* ris, int t, int *currentIndex, int* profit) {

    int bestIndex = 0;
    int bestVal = 0;
    for (size_t i = 0; i < j_size; i++)
    {
        if (appet[i] > bestVal && used[i] == 0)
        {
            bestVal = appet[i];
            bestIndex = i;
        }
    }

    if (jobs[bestIndex].deadline >= (jobs[bestIndex].duration + t) && used[bestIndex] == 0)
    {
        used[bestIndex] = 1;
        ris[*currentIndex] = bestIndex;
        *currentIndex += 1;
        *profit += jobs[bestIndex].profit;
        ScheduleJobsRec(jobs, j_size, appet, used, ris, t + jobs[bestIndex].duration, currentIndex, profit);
    }
    else if (used[bestIndex] == 0)
    {
        used[bestIndex] = 1;
        ScheduleJobsRec(jobs, j_size, appet, used, ris, t, currentIndex, profit);
    }

    return *profit;

}

int ScheduleJobs(const job* jobs, size_t j_size) {

    if (jobs == NULL || j_size <= 0)
    {
        return;
    }

    int* appet = malloc(sizeof(int) * j_size);
    int* used = calloc(j_size, sizeof(int));
    int* ris = malloc(sizeof(int));
    int currentRisIndex = 0;
    int profit = 0;

    for (size_t i = 0; i < j_size; i++)
    {
        appet[i] = jobs[i].profit / jobs[i].duration;
    }

    ScheduleJobsRec(jobs, j_size, appet, used, ris, 0, &currentRisIndex, &profit);

    for (size_t i = 0; i < currentRisIndex; i++)
    {
        printf("%d ", ris[i]);
    }

    return profit;
}