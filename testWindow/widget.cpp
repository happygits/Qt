#include "widget.h"
#include "ui_widget.h"
#include <QFont>
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Windows
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    resize(QSize(354, 271));
    setStyleSheet("border:1px solid rgb(46, 130, 255); background-color:rgb(255, 255, 255);");

    //Topframe
    topFrame.setParent(this);
    topFrame.resize(QSize(geometry().width(), 30));
    topFrame.move(geometry().x(), geometry().y());
    topFrame.setStyleSheet("background-color:rgb(46, 130, 255);");

    //titleLabel
    titleLabel.setParent(this);
    titleLabel.setStyleSheet("border:none;background-color:none; color:rgb(255, 255, 255);");
    QFont titleFont;
    titleFont.setPointSize(12);
    titleLabel.setFont(titleFont);
    titleLabel.setText("方德防火墙");

    //mini
    mini.setParent(this);
    mini.setMinimumSize(24, 24);
    mini.setMaximumSize(24, 24);
    mini.setStyleSheet("QPushButton{image:url(:/new/prefix1/res/mini.png);border:none; background-color:none}"
                       "QPushButton:pressed{background-color:rgb(30, 80, 255)}");
    //close
    close.setParent(this);
    close.setStyleSheet("QPushButton{image:url(:/new/prefix1/res/close.png);border:none; background-color:none;}"
                        "QPushButton:pressed{background-color:rgb(30, 80, 255);}");
    close.setMinimumSize(24, 24);
    close.setMaximumSize(24, 24);

   // frameLayout.setParent(this);
    frameLayout.setSpacing(0);
    frameLayout.setContentsMargins(10,4, 10, 4);
    frameLayout.addWidget(&titleLabel);
    frameLayout.addWidget(&mini);
    frameLayout.addWidget(&close);
    topFrame.setLayout(&frameLayout);

    connect(&mini, &QPushButton::clicked, this, &Widget::on_miniButtonClicked);
    connect(&close, &QPushButton::clicked, this, &Widget::on_closeButtonClicked);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    qDebug() << "paintEvent";
    QPainter painter(this);
    //fill whole borday with brush
    painter.setRenderHint(QPainter::Antialiasing, true);
 /*
    QPainterPath path;
    path.addRect(0, 0, this->width(), this->height());
    painter.fillPath(path, QBrush(Qt::white));
    */
    painter.fillRect(rect(), Qt::white);//equal to the comment statements

    //draw border
    QColor color(0, 0, 0, 50);
    for(int i=0; i<1;i++){//border 2px
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(i, i, this->width() -2*i, this->height() - 2*i);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    relativePos = event->globalPos() - window()->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    window()->move(event->globalPos() - relativePos);
}

void Widget::on_miniButtonClicked()
{
    window()->hide();
}

void Widget::on_closeButtonClicked()
{
    window()->close();
}
