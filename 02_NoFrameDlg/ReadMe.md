# Qt创建无边框的异形对话窗口

## Step 1
使用`setAttribute`和`setWindowFlags`实现去窗口化和透明背景
```CPP
this->setAttribute(Qt::WA_TranslucentBackground);  //透明背景
//this->setWindowOpacity(0.5);
Qt::WindowFlags flags = this->windowFlags();
this->setWindowFlags(flags | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
this->setWindowModality(Qt::WindowModal);
```


## Step 2
重写`paintEvent`实现自定义背景颜色和异型窗口
```CPP
QPainter painter(this);
painter.setRenderHint(QPainter::Antialiasing); //反锯齿
painter.setPen(borderColor_);
painter.setBrush(backgroundColor_);
QRect rect = this->rect();
rect.setWidth(rect.width()-1);
rect.setHeight(rect.height()-1);
painter.drawRoundedRect(rect,30,30);
QWidget::paintEvent(e);
```