#include "NoFrameDialog.h"

#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NoFrameDialog w;
    w.setBorderColor(Qt::black);
    w.setBorderWidth(5);
    w.setBackground(Qt::white);
    w.setRadus(10);
    QHBoxLayout* layout = new QHBoxLayout;
    QLabel* label = new QLabel(QObject::tr("无边框窗口"));
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);
    w.setLayout(layout);
    w.resize(640, 480);
    w.show();
    return a.exec();
}
