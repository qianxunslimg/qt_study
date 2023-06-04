/** @file   StaticCallBackTest.h
 *  @brief  ��̬�ص������������Ա��������demo
 *  @note
 *  @author lesliefish
 *  @date   2019/03/22
 */
#pragma once

#include <QObject>

#if defined _WIN32 || defined _WIN64
#define CALLBACK __stdcall
#elif defined __linux__ || defined __APPLE__
#define CALLBACK
#endif

// ����ص���������
typedef void(CALLBACK *CALLBACK_FUNC)(const char *str, void *pUserData);

// �ص�����ӿ�
void setCallBackFunc(CALLBACK_FUNC pFuncCallBack, void *data = nullptr);

class StaticCallBackTest : public QObject
{
    Q_OBJECT

public:
    StaticCallBackTest(QObject *parent = Q_NULLPTR);

public:
    // ��̬��ָ��
    static StaticCallBackTest *s_this;
    // ��̬���� ��doSomething()����
    static void CALLBACK startFunc(const char *str, void *pData);

public:
    // ����
    void start();

signals:
    // �����ź�
    void signalTest(const std::string &str);
};
