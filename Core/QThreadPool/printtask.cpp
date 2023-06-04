#include "printtask.h"
#include <QThread>
#include <iostream>
using std::cout;
using std::endl;

PrintTask::PrintTask()
{
}

PrintTask::~PrintTask()
{
}

void PrintTask::run()
{
    cout << "PrintTask run �����ã������߳�IDΪ��" << QThread::currentThread() << endl;
}
