#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPoint>
#include <QMouseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    Ui::Widget *ui;
    QFrame topFrame;
    QLabel titleLabel;
    QPushButton mini;
    QPushButton close;
    QHBoxLayout frameLayout;
    QPoint relativePos;

private slots:
    void on_miniButtonClicked();
    void on_closeButtonClicked();
};

#endif // WIDGET_H
