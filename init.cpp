#include "init.h"
#include "ui_init.h"
#include "ticTacToe.h"
#include "init2.h"
init::init(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::init)
{
    ui->setupUi(this);
}

init::~init()
{
    delete ui;
}

void init::on_pushButton_3_clicked()
{
    exit(0);
}

void init::on_pushButton_2_clicked()
{
	ticTacToe *tt=new ticTacToe;
    this->close();
    tt->com=0;
    tt->ok=1;
    tt->show();
}

void init::on_pushButton_clicked()
{
    init2 *tt=new init2;
    this->close();
    tt->show();
}
