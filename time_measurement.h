#ifndef TIME_MEASUREMENT_H
#define TIME_MEASUREMENT_H

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdint.h>

long eval_time(struct timeval begin,struct timeval end);

#endif // TIME_MEASUREMENT_H
