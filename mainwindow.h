
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_00_clicked();

    void on_pushButton_01_clicked();

    void on_pushButton_02_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::MainWindow *ui;
    QChar  board[3][3];
    const QChar x='X';
    const QChar o='O';
    const QChar emp=' ';
    QPushButton* buttons[3][3];

    QChar human;
    QChar comp;
    void display();
    void move_human(QChar human);
    void move_comp(QChar comp);
    void all_block();
    bool isend();
};

#endif // MAINWINDOW_H
