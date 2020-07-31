#include "ticTacToe.h"
#include "init2.h"
#include "ui_ticTacToe.h"
#include<QPainter>

ticTacToe::ticTacToe(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ticTacToe)//ticTacToe����QMainWindow���Ui_Tic_Tac_Toe��̳ж���
{//���µ�ui����Ui_Tic_Tac_Toe��
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

//��������λ��
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

//�����˻���ս����˫�˶�ս��ѡ��--��ʼ��
void ticTacToe::paintEvent(QPaintEvent *event)
{
	QPixmap pixmap = QPixmap(":/new/prefix1/p.png").scaled(this->size());
	QPainter painter(this);
	painter.drawPixmap(this->rect(), pixmap);//���Ʊ���ͼƬ
	QBrush brush(Qt::Dense6Pattern);//QBrush��һ�������ߵ�pattern����
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
	if (!com)//com=0ʱΪ˫�˶�ս
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

//�ж��Ƿ���Ϸ����
int ticTacToe::gameover()
{
	//����Ϊ6�ֻ�ʤ��������ػ�ʤ��ҷ���
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
			if (chess[i][j] == 0) { flag = 0; break; }//������һ���ط�û����������
		}
	}
	if (flag)return 3;//������������꣬��û�зֳ�ʤ�������
	return 0;//����0��ʾ��Ϸ����
}

//��Ϸ������������ÿ�����Ӻ����
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
			ui->lineEdit_2->setText("ƽ��");
			ok = 0;
		}
		turn *= -1;
	}
	else//�˻��Կ�
	{
		if (xx == turn)
		{
			ui->lineEdit_2->setText("Player WIN");
			ok = 0;
		}
		else if (xx == 3)
		{
			ui->lineEdit_2->setText("ƽ��");
			ok = 0;
		}
		else//��Ϸ��������
		{
			int bestmove = -1, value;
			if (com == 1)findcommove(&bestmove, &value);
			else findhumanmove(&bestmove, &value);//���ֵĻ������������-1
			chess[bestmove % 3][bestmove / 3] = turn * (-1);
			xx = gameover();
			if (xx == turn * (-1))//��ǰ���ӣ������������ʤ
			{
				ui->lineEdit_2->setText("Computer WIN");
				ok = 0;
			}
			else if (xx == 3)
			{
				ui->lineEdit_2->setText("ƽ��");
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

//���¿�ʼ
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
//�˳���Ϸ
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
	else//��Ϸ��������
	{
		*value = -1;
		for (int i = 0; i < 9; i++)
		{

			if (!chess[i % 3][i / 3])
			{
				chess[i % 3][i / 3] = 1;
				findhumanmove(&bb, &response);
				chess[i % 3][i / 3] = 0;//�ҵ�bestmove��ָ�����
				if (response > *value)//ֱ���ҵ��������ʤ����ƽ�ֵ�����λ�ã�����max
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
				if (response < *value)//��������������ʤ������min
				{
					*value = response;
					*bestmove = i;
				}
			}
		}
	}
}
