#include "jobs.h"

int main(void) {

	job j[] = { {50, 2, 4}, {130, 4, 25}, {35, 1, 3}, {50, 8, 30}, {300, 4, 7}, {145, 20, 30} };

	ScheduleJobs(j, 6);

}