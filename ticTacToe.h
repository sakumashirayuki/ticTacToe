#pragma once
#ifndef  TICTACTOE_H
#define TICTACTOE_H

#include <QtWidgets/QMainWindow>

namespace Ui {
	class ticTacToe;
}

class ticTacToe : public QMainWindow
{
	Q_OBJECT

public:
	explicit ticTacToe(QWidget *parent = 0);
	~ticTacToe();
	void paintEvent(QPaintEvent *event);
	void paint(int x, int y, int label);
	int gameover();
	void findcommove(int *bestmove, int *value);
	void findhumanmove(int *bestmove, int *value);
	void res();
	int com;
	int chess[3][3];
	int turn = 1;
	bool ok;

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_7_clicked();

	void on_pushButton_5_clicked();

	void on_pushButton_8_clicked();

	void on_pushButton_6_clicked();

	void on_pushButton_9_clicked();

	void on_pushButton_10_clicked();

	void on_pushButton_11_clicked();

private:
	Ui::ticTacToe *ui;
};

#endif // ! TICTACTOE_H



