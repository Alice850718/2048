#include "result.h"
#include "ui_result.h"
#include "game.h"

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
