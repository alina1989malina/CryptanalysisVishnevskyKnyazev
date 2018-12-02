#include "time_measurement.h"



long eval_time(struct timeval start,struct timeval end){
    // служебные переменные для замера времени
    long mtime, seconds, useconds;

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    // Переводим всё в миллисекунды и вычисляем разницу
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;

    //распечатываем время выполнения
    //cout<<"Elapsed time: "<<mtime<<" milliseconds\n";

    return mtime;
}
