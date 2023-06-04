#include <QQuickWidget>
#include <QQuickItem>
#include <QWidget>
#include <QPushButton>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建一个 QQuickWidget 对象
    QQuickWidget w;

    // 设置 QML 文件的源，这里使用 qrc 资源路径指定 main.qml
    w.setSource(QUrl(QStringLiteral("qrc:/QtAppCallQml/Resources/main.qml")));

    // 设置 QQuickWidget 的大小策略为自适应根对象的大小
    w.setResizeMode(QQuickWidget::SizeRootObjectToView);

    // 显示 QQuickWidget
    w.show();

    // 创建一个 QPushButton 对象，并将其父对象设置为 QQuickWidget
    QPushButton btn(&w);

    // 设置按钮的文本
    btn.setText("Change Page 1 Color to lightblue");

    // 显示按钮
    btn.show();

    // 在 QQuickWidget 的根对象中查找名为 "swipeViewObj" 的子对象
    auto swipeView = w.rootObject()->findChild<QObject *>("swipeViewObj");

    // 在 QQuickWidget 的根对象中查找名为 "page1Obj" 的子对象
    auto page1 = w.rootObject()->findChild<QObject *>("page1Obj");

    // 判断查找结果是否为 nullptr
    if (swipeView != nullptr)
    {
        if (page1 != nullptr)
        {
            // 当按钮被点击时，通过 QMetaObject::invokeMethod 调用 QML 中的 setColor 方法，设置 page1 的颜色为 "lightblue"
            QObject::connect(&btn, &QPushButton::clicked, [&]
                             { QMetaObject::invokeMethod(page1, "setColor", Q_ARG(QVariant, "lightblue")); });
        }

        // 当 swipeView 的当前索引发生变化时，调用 QQuickWidget 的 showMaximized() 槽函数
        QObject::connect(swipeView, SIGNAL(currentIndexChanged()), &w, SLOT(showMaximized()));
    }

    // 运行应用程序的事件循环
    return a.exec();
}
