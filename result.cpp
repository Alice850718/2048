#include "game.h"
#include "result.h"
#include "mainwindow.h"
#include "ui_result.h"
#include <QLCDNumber>

result::result(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
}

result::~result()
{
    delete ui;
}

void result::on_pushButton_3_clicked()
{
    close();
    Game *game = new Game(this);
    game->show();
}


void result::on_pushButton_4_clicked()
{
    close();
}
