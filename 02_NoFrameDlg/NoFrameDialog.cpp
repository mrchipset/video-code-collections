#include "NoFrameDialog.h"
#include <QPainter>

NoFrameDialog::NoFrameDialog(QWidget *parent)
    : QDialog(parent),
      mBorderPen(Qt::red),
      mBackground(Qt::gray),
      mRadus(30)
{
    // setAttribute and setWindowFlags
    setAttribute(Qt::WA_TranslucentBackground);
    Qt::WindowFlags flags = windowFlags();
    setWindowFlags(flags | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
}

NoFrameDialog::~NoFrameDialog()
{
}

void NoFrameDialog::setBorderColor(const QColor &border)
{
    mBorderPen.setColor(border);
}

void NoFrameDialog::setBorderWidth(const int width)
{
    mBorderPen.setWidth(width);
}

void NoFrameDialog::setBackground(const QColor &background)
{
    mBackground = background;
}

void NoFrameDialog::setRadus(int radus)
{
    mRadus = radus;
}

void NoFrameDialog::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(mBorderPen);
    painter.setBrush(QBrush(mBackground));
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, mRadus, mRadus);
    QWidget::paintEvent(ev);
}

