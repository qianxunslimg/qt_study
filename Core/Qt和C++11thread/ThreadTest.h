/** @file   ThreadTest.h
 *
 * @brief  ʹ��std::thread�߳̽��Qt���濨������
 * @author lesliefish
 * @date   2018/08/31
 */
#pragma once

#include <QPushButton>
#include <QEventLoop>
#include <QtWidgets/QWidget>
#include "ui_ThreadTest.h"

class ThreadTest : public QWidget
{
    Q_OBJECT

public:
    explicit ThreadTest(QWidget *parent = Q_NULLPTR);

signals:
    // �߳̽����ź�
    void signalRunOver();

private:
    // ���Ժ���
    void test();

private:
    Ui::ThreadTestClass ui;
};
