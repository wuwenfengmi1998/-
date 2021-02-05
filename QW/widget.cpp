#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QTimer>

struct care
{
    int num;
    long color;

};

care car[10][10];

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTimer *mainrun;


    for(int y=0;y<10;y++)
    {
        for(int x=0;x<10;x++)
        {
            car[y][x].color=0xffffff;
            car[y][x].num=0;
        }

    }

    mainrun = new QTimer(this);
    connect(mainrun,&QTimer::timeout,this,&Widget::mainrun_timeout);
    mainrun->start(1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    //QPainter p(this); //方法1 创建画家对象 并指定绘图设备


    /*
     *方法2 创建画家对象
     *通过bggin指定绘图设备
     *中间做绘图操作
     *结尾需要end结束
     */
    QPainter p;
    p.begin(this);


    //定义画笔
    QPen pen;
    QBrush brush;//创建笔刷






    pen.setWidth(1);//设置线宽
    pen.setColor(QColor(28,28,28));          //常用颜色
    pen.setStyle(Qt::SolidLine);    //设置风格
    p.setPen(pen);              //将画笔给画家

    brush.setStyle(Qt::SolidPattern);//设定笔刷样式




#define car_size 80
    for(int y=0;y<10;y++)
    {
        for(int x=0;x<10;x++)
        {
            brush.setColor(car[y][x].color); //设定笔刷
            p.setBrush(brush);          //笔刷交给画家
            p.drawRect(x*car_size,y*car_size,car_size,car_size);
        }

    }





    p.end();

}

void Widget::mainrun_timeout()
{
    Widget::update();
}