#include "ticTacToe.h"
#include "init2.h"
#include "ui_ticTacToe.h"
#include<QPainter>

ticTacToe::ticTacToe(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ticTacToe)//ticTacToe类由QMainWindow类和Ui_Tic_Tac_Toe类继承而来
{//以下的ui来自Ui_Tic_Tac_Toe类
    ui->setupUi(this);
	ui->lineEdit->setStyleSheet("border:1px;background-color:transparent");
	ui->lineEdit->setFont(QFont("Timers", 20, QFont::Bold));
	ui->lineEdit_2->setStyleSheet("border:1px;background-color:transparent");
	ui->lineEdit_2->setFont(QFont("Timers", 20, QFont::Bold));
}
ticTacToe::~ticTacToe()
{
	delete ui;
}

//绘制棋子位置
void ticTacToe::paint(int x, int y, int label)
{
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 4, Qt::SolidLine));
	if (label == 1)
	{
		if (y == 0)painter.drawEllipse(150 + x * 200, 75, 100, 100);
		else if (y == 1)painter.drawEllipse(150 + x * 200, 250, 100, 100);
		else painter.drawEllipse(150 + x * 200, 425, 100, 100);
	}
	else if (label == -1)
	{
		if (y == 0)
		{
			painter.drawLine(QPoint(150 + x * 200, 75), QPoint(250 + x * 200, 175));
			painter.drawLine(QPoint(150 + x * 200, 175), QPoint(250 + x * 200, 75));
		}
		else if (y == 1)
		{
			painter.drawLine(QPoint(150 + x * 200, 250), QPoint(250 + x * 200, 350));
			painter.drawLine(QPoint(150 + x * 200, 350), QPoint(250 + x * 200, 250));
		}
		else
		{
			painter.drawLine(QPoint(150 + x * 200, 425), QPoint(250 + x * 200, 525));
			painter.drawLine(QPoint(150 + x * 200, 525), QPoint(250 + x * 200, 425));
		}
	}
}

//绘制人机对战或者双人对战的选项--初始化
void ticTacToe::paintEvent(QPaintEvent *event)
{
	QPixmap pixmap = QPixmap(":/new/prefix1/p.png").scaled(this->size());
	QPainter painter(this);
	painter.drawPixmap(this->rect(), pixmap);//绘制背景图片
	QBrush brush(Qt::Dense6Pattern);//QBrush是一个定义线的pattern的类
	painter.setBrush(brush);
	painter.drawRect(100, 200, 600, 5);
	painter.drawRect(100, 400, 600, 5);
	painter.drawRect(300, 50, 5, 500);
	painter.drawRect(500, 50, 5, 500);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)paint(i, j, chess[i][j]);
	}
	QPainter pa(this);
	pa.setPen(QPen(Qt::blue, 4, Qt::SolidLine));
	if (!com)//com=0时为双人对战
	{
		if (turn == 1)
		{
			ui->lineEdit->setText("Player 1");
			pa.drawEllipse(760, 120, 100, 100);
		}
		else
		{
			ui->lineEdit->setText("Player 2");
			pa.drawLine(QPoint(760, 120), QPoint(860, 220));
			pa.drawLine(QPoint(760, 220), QPoint(860, 120));
		}
	}
	else
	{
		if (((turn + 1) / 2)&com)
		{
			ui->lineEdit->setText("Computer");
		}
		else
		{
			ui->lineEdit->setText("Player");
		}
		if (turn == 1)pa.drawEllipse(760, 120, 100, 100);
		else
		{
			pa.drawLine(QPoint(760, 120), QPoint(860, 220));
			pa.drawLine(QPoint(760, 220), QPoint(860, 120));
		}
	}
	update();
}

//判断是否游戏结束
int ticTacToe::gameover()
{
	//以下为6种获胜情况，返回获胜玩家符号
	if (chess[0][0] && chess[0][0] == chess[0][1] && chess[0][0] == chess[0][2])return chess[0][0];
	if (chess[0][0] && chess[0][0] == chess[1][1] && chess[0][0] == chess[2][2])return chess[0][0];
	if (chess[0][0] && chess[0][0] == chess[1][0] && chess[0][0] == chess[2][0])return chess[0][0];
	if (chess[0][1] && chess[0][1] == chess[1][1] && chess[0][1] == chess[2][1])return chess[0][1];
	if (chess[1][0] && chess[1][0] == chess[1][1] && chess[1][0] == chess[1][2])return chess[1][0];
	if (chess[2][0] && chess[2][0] == chess[2][1] && chess[2][0] == chess[2][2])return chess[2][0];
	if (chess[0][2] && chess[0][2] == chess[1][2] && chess[0][2] == chess[2][2])return chess[0][2];
	if (chess[2][0] && chess[2][0] == chess[1][1] && chess[2][0] == chess[0][2])return chess[2][0];
	int flag = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (chess[i][j] == 0) { flag = 0; break; }//至少有一个地方没有填上棋子
		}
	}
	if (flag)return 3;//所有区域填充完，但没有分出胜负的情况
	return 0;//返回0表示游戏继续
}

//游戏部分主函数，每次落子后调用
void ticTacToe::res()
{
	int xx = gameover();
	if (!com)
	{
		if (xx == 1)
		{
			ui->lineEdit_2->setText("Player 1 WIN");
			ok = 0;
		}
		else if (xx == -1)
		{
			ui->lineEdit_2->setText("Player 2 WIN");
			ok = 0;
		}
		else if (xx == 3)
		{
			ui->lineEdit_2->setText("平局");
			ok = 0;
		}
		turn *= -1;
	}
	else//人机对抗
	{
		if (xx == turn)
		{
			ui->lineEdit_2->setText("Player WIN");
			ok = 0;
		}
		else if (xx == 3)
		{
			ui->lineEdit_2->setText("平局");
			ok = 0;
		}
		else//游戏继续进行
		{
			int bestmove = -1, value;
			if (com == 1)findcommove(&bestmove, &value);
			else findhumanmove(&bestmove, &value);//后手的话，计算机代表-1
			chess[bestmove % 3][bestmove / 3] = turn * (-1);
			xx = gameover();
			if (xx == turn * (-1))//当前落子，即计算机方获胜
			{
				ui->lineEdit_2->setText("Computer WIN");
				ok = 0;
			}
			else if (xx == 3)
			{
				ui->lineEdit_2->setText("平局");
				ok = 0;
			}
		}
	}
}

void ticTacToe::on_pushButton_clicked()
{
	if (chess[0][0] || (!ok))return;
	chess[0][0] = turn;
	res();
}


void ticTacToe::on_pushButton_2_clicked()
{
	if (chess[1][0] || (!ok))return;
	chess[1][0] = turn;
	res();
}


void ticTacToe::on_pushButton_3_clicked()
{
	if (chess[2][0] || (!ok))return;
	chess[2][0] = turn;
	res();
}

void ticTacToe::on_pushButton_4_clicked()
{
	if (chess[0][1] || (!ok))return;
	chess[0][1] = turn;
	res();
}

void ticTacToe::on_pushButton_7_clicked()
{
	if (chess[0][2] || (!ok))return;
	chess[0][2] = turn;
	res();
}

void ticTacToe::on_pushButton_5_clicked()
{
	if (chess[1][1] || (!ok))return;
	chess[1][1] = turn;
	res();
}

void ticTacToe::on_pushButton_8_clicked()
{
	if (chess[1][2] || (!ok))return;
	chess[1][2] = turn;
	res();
}

void ticTacToe::on_pushButton_6_clicked()
{
	if (chess[2][1] || (!ok))return;
	chess[2][1] = turn;
	res();
}

void ticTacToe::on_pushButton_9_clicked()
{
	if (chess[2][2] || (!ok))return;
	chess[2][2] = turn;
	res();
}

//重新开始
void ticTacToe::on_pushButton_10_clicked()
{
	turn = 1;
	ok = 1;
	ui->lineEdit_2->setText("");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)chess[i][j] = 0;
	}
	if (com == 1)
	{
		chess[1][1] = 1;
		turn = -1;
	}
}
//退出游戏
void ticTacToe::on_pushButton_11_clicked()
{
	exit(0);
}

void ticTacToe::findcommove(int *bestmove, int *value)
{
	int bb = -1, response;
	if (gameover() == 3)*value = 0;
	else if (gameover() == 1)
	{
		*value = 1;
	}
	else if (gameover() == -1)*value = -1;
	else//游戏继续进行
	{
		*value = -1;
		for (int i = 0; i < 9; i++)
		{

			if (!chess[i % 3][i / 3])
			{
				chess[i % 3][i / 3] = 1;
				findhumanmove(&bb, &response);
				chess[i % 3][i / 3] = 0;//找到bestmove后恢复盘面
				if (response > *value)//直到找到计算机获胜或者平局的落子位置，代表max
				{
					*value = response;
					*bestmove = i;
				}
			}
		}
	}
}

void ticTacToe::findhumanmove(int *bestmove, int *value)
{
	int bb = -1, response;
	if (gameover() == 3)*value = 0;
	else if (gameover() == -1)
	{
		*value = -1;
	}
	else if (gameover() == 1)*value = 1;
	else
	{
		*value = 1;
		for (int i = 0; i < 9; i++)
		{
			if (!chess[i % 3][i / 3])
			{
				chess[i % 3][i / 3] = -1;
				findcommove(&bb, &response);
				chess[i % 3][i / 3] = 0;
				if (response < *value)//这种情况是人类获胜，代表min
				{
					*value = response;
					*bestmove = i;
				}
			}
		}
	}
}
