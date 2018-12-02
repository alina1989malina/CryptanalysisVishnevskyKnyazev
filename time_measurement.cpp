#include "time_measurement.h"



long eval_time(struct timeval start,struct timeval end){
    // ��������� ���������� ��� ������ �������
    long mtime, seconds, useconds;

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    // ��������� �� � ������������ � ��������� �������
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;

    //������������� ����� ����������
    //cout<<"Elapsed time: "<<mtime<<" milliseconds\n";

    return mtime;
}
