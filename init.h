#ifndef INIT_H
#define INIT_H

#include <QWidget>

namespace Ui {
class init;
}

class init : public QWidget
{
    Q_OBJECT

public:
    explicit init(QWidget *parent = 0);
    ~init();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::init *ui;
};

#endif // INIT_H
