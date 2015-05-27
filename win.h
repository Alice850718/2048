#ifndef WIN_H
#define WIN_H

#include <QMainWindow>
#include "game.h"
#include "mainwindow.h"

namespace Ui {
class Win;
}

class Win : public QMainWindow
{
    Q_OBJECT

public:
    explicit Win(QWidget *parent = 0);
    ~Win();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Win *ui;
};

#endif // WIN_H
