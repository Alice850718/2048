#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLCDNumber>
#include <QLabel>
#include "result.h"
#include "mainwindow.h"

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    int score;
    explicit Game(QWidget *parent = 0);
    int arr[16], arr_his[16];
    ~Game();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::Game *ui;
    Game *game;
    QLabel *arr_pic[16];
    int i, j, k, change, near, count;
    void Creat();
    void check_change();
    void check_near();
    void Combine_Up();
    void Combine_Down();
    void Combine_Right();
    void Combine_Left();
    void showpic();
    void keyPressEvent(QKeyEvent *event);

};

#endif // GAME_H
