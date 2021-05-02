#include "PrintJob.h"

PrintJob::PrintJob ( int setP, int setJ, int numP ):priority(setP), jobNumber(setJ), numPages(numP){}
int PrintJob::getPriority ( ){
    return priority;
}

int PrintJob::getJobNumber ( ){
    return jobNumber;
}

int PrintJob::getPages ( ){
    return numPages;
}

void PrintJob::setPriority(int p)
{
    priority = p;
}

void PrintJob::setJobNumber(int j)
{
    jobNumber = j;
}

void PrintJob::setPages(int p)
{
    numPages = p;
}