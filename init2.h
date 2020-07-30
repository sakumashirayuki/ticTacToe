#ifndef INIT2_H
#define INIT2_H

#include <QWidget>

namespace Ui {
class init2;
}

class init2 : public QWidget
{
    Q_OBJECT

public:
    explicit init2(QWidget *parent = 0);
    ~init2();
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::init2 *ui;
};

#endif // INIT2_H
