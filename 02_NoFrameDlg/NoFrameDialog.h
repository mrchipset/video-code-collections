#ifndef NOFRAMEDIALOG_H
#define NOFRAMEDIALOG_H

#include <QDialog>
#include <QPaintEvent>
#include <QPen>

class NoFrameDialog : public QDialog
{
    Q_OBJECT

public:
    NoFrameDialog(QWidget *parent = nullptr);
    ~NoFrameDialog();


    void setBorderColor(const QColor& border);
    void setBorderWidth(const int width);

    void setBackground(const QColor& background);
    void setRadus(int radus);
 private:
    QPen mBorderPen;
    QColor mBackground;
    int mRadus;
protected:
    virtual void paintEvent(QPaintEvent* ev) override;
};
#endif // NOFRAMEDIALOG_H
