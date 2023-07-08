
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buttons[0][0]=ui->pushButton_00;
    buttons[0][1]=ui->pushButton_01;
    buttons[0][2]=ui->pushButton_02;
    buttons[1][0]=ui->pushButton_10;
    buttons[1][1]=ui->pushButton_11;
    buttons[1][2]=ui->pushButton_12;
    buttons[2][0]=ui->pushButton_20;
    buttons[2][1]=ui->pushButton_21;
    buttons[2][2]=ui->pushButton_22;
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            buttons[i][j]->setEnabled(false);
            buttons[i][j]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;");
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display()
{
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            buttons[i][j]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;");
            buttons[i][j]->setText(board[i][j]);
        }
    }
}

void MainWindow::on_pushButton_start_clicked()
{
    ui->result->setText("");
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            buttons[i][j]->setEnabled(true);
            buttons[i][j]->setStyleSheet("background-color: white;");
            board[i][j]=' ';
        }
    }
    display();
    if(ui->radioButton_x->isChecked())
    {
        human=x;
        comp=o;
    }
    else
    {
        human=o;
        comp=x;
        move_comp(comp);
        display();
    }
}

void MainWindow::move_human(QChar human)
{

}
void MainWindow::move_comp(QChar comp)
{
    //2 в ряд компа
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            //рядок
            if(board[i][j]==comp&&board[i][(j+1)%3]==comp&&board[i][(j+2)%3]==emp)
            {
                board[i][(j+2)%3]=comp;
                buttons[i][(j+2)%3]->setEnabled(false);

                return;
            }
            //стовпчик
            if(board[i][j]==comp&&board[(i+1)%3][j]==comp&&board[(i+2)%3][j]==emp)
            {
                board[(i+2)%3][j]=comp;
                buttons[(i+2)%3][j]->setEnabled(false);

                return;
            }
            //діаг
            if(board[0][0]==comp&&board[1][1]==comp&&board[2][2]==emp)
            {
                board[2][2]=comp;
                buttons[2][2]->setEnabled(false);

                return;
            }
            if(board[2][2]==comp&&board[1][1]==comp&&board[0][0]==emp)
            {
                board[0][0]=comp;
                buttons[0][0]->setEnabled(false);

                return;
            }
            if(board[2][2]==comp&&board[0][0]==comp&&board[1][1]==emp)
            {
                board[1][1]=comp;
                buttons[1][1]->setEnabled(false);

                return;
            }
            //друга діагональ
            if(board[0][2]==comp&&board[1][1]==comp&&board[2][0]==emp)
            {
                board[2][0]=comp;
                buttons[2][0]->setEnabled(false);

                return;
            }
            if(board[0][2]==comp&&board[2][0]==comp&&board[1][1]==emp)
            {
                board[1][1]=comp;
                buttons[1][1]->setEnabled(false);

                return;
            }
            if(board[2][0]==comp&&board[1][1]==comp&&board[0][2]==emp)
            {
                board[0][2]=comp;
                buttons[0][2]->setEnabled(false);

                return;
            }
        }
    }
    //2 в ряд юзера
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            //рядок
            if(board[i][j]==human&&board[i][(j+1)%3]==human&&board[i][(j+2)%3]==emp)
            {
                board[i][(j+2)%3]=comp;
                buttons[i][(j+2)%3]->setEnabled(false);

                return;
            }
            //стовпчик
            if(board[i][j]==human&&board[(i+1)%3][j]==human&&board[(i+2)%3][j]==emp)
            {
                board[(i+2)%3][j]=comp;
                buttons[(i+2)%3][j]->setEnabled(false);

                return;
            }
            //діаг
            if(board[0][0]==human&&board[1][1]==human&&board[2][2]==emp)
            {
                board[2][2]=comp;
                buttons[2][2]->setEnabled(false);

                return;
            }
            if(board[2][2]==human&&board[1][1]==human&&board[0][0]==emp)
            {
                board[0][0]=comp;
                buttons[0][0]->setEnabled(false);

                return;
            }
            if(board[2][2]==human&&board[0][0]==human&&board[1][1]==emp)
            {
                board[1][1]=comp;
                buttons[1][1]->setEnabled(false);

                return;
            }
            //друга діагональ
            if(board[0][2]==human&&board[1][1]==human&&board[2][0]==emp)
            {
                board[2][0]=comp;
                buttons[2][0]->setEnabled(false);

                return;
            }
            if(board[0][2]==human&&board[2][0]==human&&board[1][1]==emp)
            {
                board[1][1]=comp;
                buttons[1][1]->setEnabled(false);

                return;
            }
            if(board[2][0]==human&board[1][1]==human&&board[0][2]==emp)
            {
                board[0][2]=comp;
                buttons[0][2]->setEnabled(false);

                return;
            }
        }
    }
    //рандом
    while(true)
    {
        int r=rand()%3;
        int s=rand()%3;
        if(board[r][s]==' ')
        {
            board[r][s]=comp;
            buttons[r][s]->setEnabled(false);

            return;
        }

    }


}
bool MainWindow::isend()
{
    for(int i=0;i<3;i++)
    {
        if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][2]!=emp)
        {
            buttons[i][0]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
            buttons[i][1]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
            buttons[i][2]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
            if(board[i][2]==comp)ui->result->setText("Переміг комп'ютер");
            else ui->result->setText("Перемога Ваша!");
            return true;
        }

        if (board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[2][i]!=emp)
        {
            buttons[0][i]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
            buttons[1][i]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
            buttons[2][i]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
            if(board[0][i]==comp)ui->result->setText("Переміг комп'ютер");
            else ui->result->setText("Перемога Ваша!");
            return true;
        }
    }
    if(board[1][1]==board[0][0]&&board[0][0]==board[2][2]&&board[2][2]!=emp)
    {
        buttons[0][0]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
        buttons[1][1]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
        buttons[2][2]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
        if(board[0][0]==comp)ui->result->setText("Переміг комп'ютер");
        else ui->result->setText("Перемога Ваша!");
        return true;
    }

    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]!=emp)
    {
        buttons[0][2]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
        buttons[1][1]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
        buttons[2][0]->setStyleSheet("font: bold;font-size: 70px;height: 100px;width: 100px;background-color: yellow;");
        if(board[0][2]==comp)ui->result->setText("Переміг комп'ютер");
        else ui->result->setText("Перемога Ваша!");
        return true;
    }
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
           if (board[i][j]==emp)return false;
        }
    }
    ui->result->setText("Нічия!");
    return true;
}
void MainWindow::all_block()
{
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {

            buttons[i][j]->setEnabled(false);
        }
    }
}
void MainWindow::on_pushButton_00_clicked()
{
    if(isend())all_block();
    else
    {
        board[0][0]=human;
        buttons[0][0]->setEnabled(false);
    }
    display();
    if(isend())all_block();
    else
    {
        move_comp(comp);
        display();
    }
    if(isend())all_block();
}


void MainWindow::on_pushButton_01_clicked()
{
    if(isend())all_block();
    else
    {
        board[0][1]=human;
        buttons[0][1]->setEnabled(false);
    }
    display();
    if(isend())all_block();
    else
    {
        move_comp(comp);
        display();
    }
    if(isend())all_block();
}


void MainWindow::on_pushButton_02_clicked()
{
    if(isend())all_block();
    else
    {
        board[0][2]=human;
        buttons[0][2]->setEnabled(false);
    }
    display();
    if(isend())all_block();
    else
    {
        move_comp(comp);
        display();
    }
    if(isend())all_block();
}


void MainWindow::on_pushButton_10_clicked()
{
    if(isend())all_block();
    else
    {
        board[1][0]=human;
        buttons[1][0]->setEnabled(false);
    }
    display();
    if(isend())all_block();
    else
    {
        move_comp(comp);
        display();
    }
    if(isend())all_block();
}


void MainWindow::on_pushButton_11_clicked()
{
    if(isend())all_block();
    else
    {
        board[1][1]=human;
        buttons[1][1]->setEnabled(false);
    }
    display();
    if(isend())all_block();
    else
    {
        move_comp(comp);
        display();
    }
    if(isend())all_block();
}


void MainWindow::on_pushButton_12_clicked()
{
    if(isend())all_block();
    else
    {
        board[1][2]=human;
        buttons[1][2]->setEnabled(false);
    }
    display();
    if(isend())all_block();
    else
    {
        move_comp(comp);
        display();
    }
    if(isend())all_block();
}


void MainWindow::on_pushButton_20_clicked()
{
    if(isend())all_block();
    else
    {
        board[2][0]=human;
        buttons[2][0]->setEnabled(false);
    }
    display();
    if(isend())all_block();
    else
    {
        move_comp(comp);
        display();
    }
    if(isend())all_block();
}


void MainWindow::on_pushButton_21_clicked()
{
    if(isend())all_block();
    else
    {
        board[2][1]=human;
        buttons[2][1]->setEnabled(false);
    }
    display();
    if(isend())all_block();
    else
    {
        move_comp(comp);
        display();
    }
    if(isend())all_block();
}


void MainWindow::on_pushButton_22_clicked()
{
    if(isend())all_block();
    else
    {
        board[2][2]=human;
        buttons[2][2]->setEnabled(false);
    }
    display();
    if(isend())all_block();
    else
    {
        move_comp(comp);
        display();
    }
    if(isend())all_block();
}

