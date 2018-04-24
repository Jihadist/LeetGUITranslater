#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QLabel *test = new QLabel(this);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_PlainTextEdit_textChanged();


    void slotClipText();


    void on_EnToLeButton_clicked();

    void on_LeToEnButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
