#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}

void Game::on_pushButton_clicked()
{
    close();
    game = new Game(this);
    game->show();
}

void Game::on_pushButton_2_clicked()
{
    close();
}

int Game::arr[16] = {0};

void Game::Creat()
{
    if(arr[rand])
}

void Game::KeyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {

    }
}