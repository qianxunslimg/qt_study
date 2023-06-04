#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyWindow.h"

enum Type
{
    LeftTop = 0, // ���Ͻ�Բ��
    RightTop,    // ���Ͻ�Բ��
    LeftBottom,  // ���½�Բ��
    RightBottom, // ���½�Բ��
    Top,         // ������Բ��
    Bottom,      // ������Բ��
    Left,        // ������Բ��
    Right,       // ������Բ��
    All          // �ĸ���Բ��
};

class MyWindow : public QWidget
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = Q_NULLPTR);

public:
    void setType(Type t);

protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::MyWindowClass ui;

    Type m_type{All};
};
