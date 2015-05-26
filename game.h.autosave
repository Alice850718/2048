#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QKeyEvent>
#include "result.h"

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void KeyPressEvent(QKeyEvent *event);

private:
    Ui::Game *ui;
    Game *game;
    int arr[16];
    int score;
    void creat();
};

#endif // GAME_H
