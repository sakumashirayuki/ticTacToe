#include "init2.h"
#include "ui_init2.h"
#include "ticTacToe.h"
#include<QPainter>
init2::init2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::init2)
{
    ui->setupUi(this);

}
void init2::paintEvent(QPaintEvent *event)
{
    QPixmap pixmap=QPixmap(":/new/prefix1/p.png").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(),pixmap);
}

init2::~init2()
{
    delete ui;
}
//选择人先手
void init2::on_pushButton_clicked()
{
	ticTacToe *tt=new ticTacToe;
    this->close();
	tt->turn = 1;
    tt->com=2;
    tt->ok=1;
    tt->show();
	for (int i = 0; i < 3; i++)//不管计算机还是人先手都先初始化为0
	{
		for (int j = 0; j < 3; j++)tt->chess[i][j] = 0;
	}
}
//选择计算机先手
void init2::on_pushButton_2_clicked()
{
	ticTacToe *tt=new ticTacToe;
    this->close();
    tt->turn=1;//先手的定义为1
    tt->ok=1;
    tt->com=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)tt->chess[i][j]=0;
    }
    if(tt->com==1)//如果计算机先手，则直接下中间
    {
        tt->chess[1][1]=1;
        tt->turn=-1;
    }
    tt->show();
}
