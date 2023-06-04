#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class MainScene : public QGraphicsScene
{
	Q_OBJECT

	// ֧�ܻ�������

public:
	MainScene(QObject *parent = nullptr);
	~MainScene();
	// ����ģ��
	void setFrontCabinet(QRectF rect);
	// LED��Ԫ
	void setLEDUnit(QRectF rect, int number, bool isVertical);
	// LCD������
	QGraphicsItem* addLCDPart(QRectF rect, int rows, int columns);
	// LED����� ���� ��
	QGraphicsItem* addVerticalLEDWithBoard(QRectF rect, int ledColumns, bool isLeft);

	// LED����� ����
	QGraphicsItem* addHorizontalLEDWithBoard(QRectF rect, int topRows, int ledWidth, int ledHeight);
	
	//  ���ӻ���
	QGraphicsItem* addCabinet(QRectF rect, int cabinetUnitWidth, int cabinetUnitHeight);

	// �������Ͻ�LED LCD��Ϣ
	QGraphicsItem* addLEDAndLCDInfo(QRectF rect);

	// �������Ͻ�����������Ϣ
	QGraphicsItem* addRightTopTextInfo(QRectF rect);


	// ���ӱ��  ������
	QGraphicsItem* addHorizontalScaleplate(QRectF rect);
	
	// ���ӱ��  ��ֱ���
	QGraphicsItem* addVerticalScaleplate(QRectF rect);
private:
	QGraphicsRectItem* m_LEDUnit;   // LED��Ԫ
	QGraphicsRectItem* m_LCDUnit;   // LCD��Ԫ
	QGraphicsRectItem* m_frontCabinet; // ����ģ��


	qreal m_bashouHeight = 12;			// �Ű��ָ߶�
	qreal m_bashouWidth = 4;		// �Ű��ֿ���

	// LCD����   
	qreal m_lcdPosX = 0;		// LCD���Ͻ���ʼ��λ��
	qreal m_lcdPosY = 0;		// LCD���Ͻ���ʼ��yλ��
	qreal m_lcdUnitWidth = 100;   // LCD��Ԫ����
	qreal m_lcdUnitHeight = 50;   // LCD��Ԫ�߶�
	int   m_lcdRows = 2;			// LCD����
	int   m_lcdColumns = 3;		// LCD����
	int   m_leftLEDColumns = 1;	// ���LED����
	int   m_rightLEDColumns = 2;	// �ұ�LED����
	int   m_topLEDRows = 2;		// ����LED����
	qreal m_ledUnitWidth = 25;	// LED����
	qreal m_ledUnitHeight = 15;	// LED�߶�
	qreal m_boardThick = 5;	    // �����
	qreal m_cabinetUnitWidth = 90;	// �����м䵥Ԫ����
	qreal m_cabinetUnitHeight = 45;// �����м䵥Ԫ�߶�
	qreal m_cabinetTopBoardThick = 5;// ����������ĺ��
	qreal m_cabinetSideBoardThick = 5;// ����֮����ĺ��
	qreal m_cabinetBottomBoardThick = 5;// ����ײ����ĺ��
};
#endif // MAINSCENE_H
