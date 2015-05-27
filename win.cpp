#include "win.h"
#include "game.h"
#include "result.h"
#include "mainwindow.h"
#include "ui_win.h"

Win::Win(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Win)
{
    ui->setupUi(this);
}

Win::~Win()
{
    delete ui;
}

void Win::on_pushButton_3_clicked()
{
    close();
    Game *game = new Game(this);
    game->show();
}

void Win::on_pushButton_4_clicked()
{
    close();
}
