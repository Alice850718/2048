#include "win.h"
#include "game.h"
#include "result.h"
#include "ui_game.h"
#include "mainwindow.h"
#include <QTime>
#include <QPixmap>
#include <QLCDNumber>
#include <stdlib.h>

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    score = 0;
    for(i = 0; i < 16; i ++)
    {
        arr[i] = 0;
    }
    arr_pic[0] = ui->pic_0;
    arr_pic[1] = ui->pic_1;
    arr_pic[2] = ui->pic_2;
    arr_pic[3] = ui->pic_3;
    arr_pic[4] = ui->pic_4;
    arr_pic[5] = ui->pic_5;
    arr_pic[6] = ui->pic_6;
    arr_pic[7] = ui->pic_7;
    arr_pic[8] = ui->pic_8;
    arr_pic[9] = ui->pic_9;
    arr_pic[10] = ui->pic_10;
    arr_pic[11] = ui->pic_11;
    arr_pic[12] = ui->pic_12;
    arr_pic[13] = ui->pic_13;
    arr_pic[14] = ui->pic_14;
    arr_pic[15] = ui->pic_15;
    Creat();
    Creat();
    score = 0;
    count = 0;
    showpic();
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

void Game::Creat()      //隨機產生2(每次一個)或-2(每3次一個)
{
    qsrand(QDateTime::currentDateTime().toTime_t());
    for(i = 0; i < 1; i ++)
    {
        int a = qrand()%16;
        if(arr[a] == 0)
        {
            if(count == 3)
            {
                arr[a] = -2;
                count = 0;
            }
            else
            {
                arr[a] = 2;
                count ++;
            }
        }
        else
        {
            i--;
        }
    }
    score = score + 2;

}

void Game::check_change()
{
    change = 0;
    for(i = 0; i < 16; i ++)
    {
    if(arr[i] != arr_his[i])
    change ++;
    }
}

void Game::check_near()
{
    near = 0;
    for(i = 0; i < 12; i ++)    //若相鄰數字相同則+1
    {
        k = i%4*4 + i/4%4;
        if(arr[i] == arr[i+4] || arr[k] == arr[k+1])
        {
            near ++;
        }
    }
    for(i = 0; i < 16; i ++)
    {
        if(arr[i] == 0)
            near ++;
    }
}

void Game::Combine_Up()
{
    for(j = 0; j < 3; j ++)
    {
        for(i = 0; i < 12; i ++)    //將數字推移
        {
            if(arr[i] == 0 && arr[i] != -4)
            {
                arr[i] = arr[i+4];
                arr[i+4] = 0;
            }
        }
    }
    for(i = 0; i < 12; i ++)    //若數字相同則結合
    {
        if(arr[i] + arr[i+4] == 0)
        {
            arr[i] = 0;
            arr[i+4] = 0;
        }
        else
        {
            if(arr[i] == arr[i+4] && arr[i] != -4)
            {
                arr[i] = arr[i]*2;
                arr[i+4] = 0;
                score = score + arr[i];
            }
        }
    }
    for(j = 0; j < 3; j ++)
    {
        for(i = 0; i < 12; i ++)    //將數字推移
        {
            if(arr[i] == 0 && arr[i+4] != -4)
            {
                arr[i] = arr[i+4];
                arr[i+4] = 0;
            }
        }
    }
}

void Game::Combine_Down()
{
    for(j = 0; j < 3; j ++)
    {
        for(i = 15; i > 3; i --)    //將數字推移
        {
            if(arr[i] == 0 && arr[i-4] != -4)
            {
                arr[i] = arr[i-4];
                arr[i-4] = 0;
            }
        }
    }
    for(i = 15; i > 3; i --)    //若數字相同則結合
    {
        if(arr[i] + arr[i-4] == 0)
        {
            arr[i] = 0;
            arr[i-4] = 0;
        }
        else
        {
            if(arr[i] == arr[i-4] && arr[i] != -4)
            {
                arr[i] = arr[i] + arr[i-4];
                arr[i-4] = 0;
                score = score + arr[i];
            }
        }
    }
    for(j = 0; j < 3; j ++)
    {
        for(i = 15; i > 3; i --)    //將數字推移
        {
            if(arr[i] == 0 && arr[i-4] != -4)
            {
                arr[i] = arr[i-4];
                arr[i-4] = 0;
            }
        }
    }
}

void Game::Combine_Left()
{
    for(j = 0; j < 3; j ++)
    {
        for(i = 0; i < 12; i ++)    //將數字推移
        {
            k = i%4*4 + i/4%4;
            if(arr[k] == 0 && arr[k+1] != -4)
            {
                arr[k] = arr[k+1];
                arr[k+1] = 0;
                score = score + arr[k];
            }
        }
    }
    for(i = 0; i < 12; i ++)    //若數字相同則結合
    {
        k = i%4*4 + i/4%4;
        if(arr[k] + arr[k+1] == 0)
        {
            arr[k] = 0;
            arr[k+1] = 0;
        }
        else
        {
            if(arr[k] == arr[k+1] && arr[k] != -4)
            {
                arr[k] = arr[k] + arr[k+1];
                arr[k+1] = 0;
                score = score + arr[k];
            }
        }
    }
    for(j = 0; j < 3; j ++)
    {
        for(i = 0; i < 12; i ++)    //將數字推移
        {
            k = i%4*4 + i/4%4;
            if(arr[k] == 0 && arr[k+1] != -4)
            {
                arr[k] = arr[k+1];
                arr[k+1] = 0;
                score = score + arr[k];
            }
        }
    }
}

void Game::Combine_Right()
{
    for(j = 0; j < 3; j ++)
    {
        for(i = 15; i > 3; i --)    //將數字推移
        {
            k = i%4*4 + i/4%4;
            if(arr[k] == 0 && arr[k-1] != -4)
            {
                arr[k] = arr[k-1];
                arr[k-1] = 0;
                score = score + arr[k];
            }
        }
    }
    for(i = 15; i > 3; i --)    //若數字相同則結合
    {
        k = i%4*4 + i/4%4;
        if(arr[k] + arr[k-1] == 0)
        {
            arr[k] = 0;
            arr[k-1] = 0;
        }
        else
        {
            if(arr[k] == arr[k-1] && arr[k] != -4)
            {
                arr[k] = arr[k] + arr[k-1];
                arr[k-1] = 0;
                score = score + arr[k];
            }
        }
    }
    for(j = 0; j < 3; j ++)
    {
        for(i = 15; i > 3; i --)    //將數字推移
        {
            k = i%4*4 + i/4%4;
            if(arr[k] == 0 && arr[k-1] != -4)
            {
                arr[k] = arr[k-1];
                arr[k-1] = 0;
                score = score + arr[k];
            }
        }
    }
}

void Game::keyPressEvent(QKeyEvent *event)
{
    for(i=0;i<16;i++)
    {
        arr_his[i]=arr[i];
        if(arr[i] == 2048)
        {
            close();
            Win *win = new Win(this);
            win->show();
        }
    }
    if(event->key() == Qt::Key_W)
    {
        Combine_Up();
    }
    if(event->key() == Qt::Key_S)
    {
        Combine_Down();
    }
    if(event->key() == Qt::Key_A)
    {
        Combine_Left();
    }
    if(event->key() == Qt::Key_D)
    {
        Combine_Right();
    }
    check_change();
    if(change != 0)
    {
        Creat();
        showpic();
    }
    else
    {
        check_near();
        if(near == 0)
        {
            close();
            result *re = new result(this);
            re->show();
        }
    }
}

void Game::showpic()
{
    for(i = 0; i < 16; i ++)
    {
        switch (arr[i])
        {
            case -4:
                arr_pic[i]->setPixmap(QPixmap(":/-4.png"));
            break;
            case -2:
                arr_pic[i]->setPixmap(QPixmap(":/-2.png"));
            break;
            case 0:
                arr_pic[i]->setPixmap(QPixmap(":/0.png"));
            break;
            case 2:
                arr_pic[i]->setPixmap(QPixmap(":/2.png"));
            break;
            case 4:
                arr_pic[i]->setPixmap(QPixmap(":/4.png"));
            break;
            case 8:
                arr_pic[i]->setPixmap(QPixmap(":/8.png"));
            break;
            case 16:
                arr_pic[i]->setPixmap(QPixmap(":/16.png"));
            break;
            case 32:
                arr_pic[i]->setPixmap(QPixmap(":/32.png"));
            break;
            case 64:
                arr_pic[i]->setPixmap(QPixmap(":/64.png"));
            break;
            case 128:
                arr_pic[i]->setPixmap(QPixmap(":/128.png"));
            break;
            case 256:
                arr_pic[i]->setPixmap(QPixmap(":/256.png"));
            break;
            case 512:
                arr_pic[i]->setPixmap(QPixmap(":/512.png"));
            break;
            case 1024:
                arr_pic[i]->setPixmap(QPixmap(":/1024.png"));
            break;
            case 2048:
                arr_pic[i]->setPixmap(QPixmap(":/2048.png"));
            break;
        }

    }
    ui->lcdnumber->display(score);
}
