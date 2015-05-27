#ifndef RESULT_H
#define RESULT_H

#include <QMainWindow>
#include "mainwindow.h"
#include "game.h"

namespace Ui {
class result;
}

class result : public QMainWindow
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::result *ui;
//    Game *game;
};

#endif // RESULT_H
