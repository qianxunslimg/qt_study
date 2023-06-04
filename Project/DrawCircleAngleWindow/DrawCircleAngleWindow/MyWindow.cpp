#include "MyWindow.h"
#include <QPainter>

MyWindow::MyWindow(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

void MyWindow::setType(Type t)
{
    m_type = t;
}

void MyWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // �����

    painter.setClipping(true);
    QPainterPath canDrawingPathArea; // �ܻ��ϵ�����
    canDrawingPathArea.addRoundedRect(rect(), 50, 50);
    canDrawingPathArea.setFillRule(Qt::WindingFill); // �������������ģʽ

    switch (m_type)
    {
    case LeftTop: // ���Ͻ�Բ��
    {
        canDrawingPathArea.addRect(0, height() - 50, 50, 50);            // ������½�
        canDrawingPathArea.addRect(width() - 50, 0, 50, 50);             // ������Ͻ�
        canDrawingPathArea.addRect(width() - 50, height() - 50, 50, 50); // ������½�
        break;
    }
    case RightTop: // ���Ͻ�Բ��
    {
        canDrawingPathArea.addRect(0, height() - 50, 50, 50);            // ������½�
        canDrawingPathArea.addRect(0, 0, 50, 50);                        // ������Ͻ�
        canDrawingPathArea.addRect(width() - 50, height() - 50, 50, 50); // ������½�
        break;
    }
    case LeftBottom: // ���½�Բ��
    {
        canDrawingPathArea.addRect(width() - 50, 0, 50, 50);             // ������Ͻ�
        canDrawingPathArea.addRect(width() - 50, height() - 50, 50, 50); // ������½�
        canDrawingPathArea.addRect(0, 0, 50, 50);                        // ������Ͻ�
        break;
    }
    case RightBottom: // ���½�Բ��
    {
        canDrawingPathArea.addRect(0, height() - 50, 50, 50); // ������½�
        canDrawingPathArea.addRect(width() - 50, 0, 50, 50);  // ������Ͻ�
        canDrawingPathArea.addRect(0, 0, 50, 50);             // ������Ͻ�
        break;
    }
    case Top: // ������Բ��
    {
        canDrawingPathArea.addRect(0, height() - 50, 50, 50);            // ������½�
        canDrawingPathArea.addRect(width() - 50, height() - 50, 50, 50); // ������½�
        break;
    }
    case Bottom: // ������Բ��
    {
        canDrawingPathArea.addRect(width() - 50, 0, 50, 50); // ������Ͻ�
        canDrawingPathArea.addRect(0, 0, 50, 50);            // ������Ͻ�
        break;
    }
    case Left: // ������Բ��
    {
        canDrawingPathArea.addRect(width() - 50, 0, 50, 50);             // ������Ͻ�
        canDrawingPathArea.addRect(width() - 50, height() - 50, 50, 50); // ������½�
        break;
    }
    case Right: // ������Բ��
    {
        canDrawingPathArea.addRect(0, height() - 50, 50, 50); // ������½�
        canDrawingPathArea.addRect(0, 0, 50, 50);             // ������Ͻ�
        break;
    }
    case All: // �ĸ���Բ��
    {
        break;
    }
    default:
        break;
    }
    painter.setClipPath(canDrawingPathArea);

    QColor color(Qt::darkRed);
    color.setAlpha(200);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    painter.drawRect(rect());

    return QWidget::paintEvent(event);
}
