#include "ThreadTest.h"
#include <thread>

ThreadTest::ThreadTest(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    // ���ź�  �����ť��ִ��test����
    connect(ui.pushButton, &QPushButton::clicked, [&]
            { test(); });
}

void ThreadTest::test()
{
    bool runResult{false};                                               // 声明并初始化一个布尔型变量 runResult，初始值为 false
    QEventLoop loop;                                                     // 创建一个事件循环对象 loop
    connect(this, &ThreadTest::signalRunOver, &loop, &QEventLoop::quit); // 将 signalRunOver 信号连接到 loop 的 quit() 槽函数

    std::thread testThread([&] // 创建一个新的线程，Lambda 函数作为线程的执行体
                           {
                               runResult = true;     // 在新线程中将 runResult 的值设为 true
                               emit signalRunOver(); // 发送 signalRunOver 信号，通知主线程执行结束
                           });

    testThread.detach(); // 分离新线程，使其在后台运行
    loop.exec();         // 执行事件循环，等待 signalRunOver 信号被触发
    if (!runResult)      // 如果 runResult 的值为 false（未被修改），则执行以下代码块
    {
        // 这里可以添加相应的处理逻辑
    }
}
