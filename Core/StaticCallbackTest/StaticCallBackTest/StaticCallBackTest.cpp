#include "StaticCallBackTest.h"
#include <thread>
#include <QDebug>

void setCallBackFunc(CALLBACK_FUNC pFuncCallBack, void *data /*= nullptr*/)
{
    std::thread t([&pFuncCallBack]
                  {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(3)); 
            std::string str = "callback test";
            pFuncCallBack(str.c_str(), nullptr); 
        } });
    t.join();
}

StaticCallBackTest *StaticCallBackTest::s_this = nullptr;

StaticCallBackTest::StaticCallBackTest(QObject *parent)
    : QObject(parent)
{
    s_this = this;
    connect(this, &StaticCallBackTest::signalTest, [this](const std::string &str)
            { qDebug() << QString::fromStdString(str); });
}

void CALLBACK StaticCallBackTest::startFunc(const char *str, void *pData)
{
    emit s_this->signalTest(std::string(str));
}

void StaticCallBackTest::start()
{
    setCallBackFunc(&startFunc);
}