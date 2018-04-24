//#define QT_NO_CAST_FROM_ASCII
//#define QT_NO_CAST_TO_ASCII

#include <sstream>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "l33t_desc.cpp"
#include "EngTol33t_func.cpp"
#include "L33tToEng_func.cpp"
#include <QTextStream>
#include <QClipboard>

#include <QTimer>


QString BufClipboard;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    connect(ui->CopyButton, SIGNAL(clicked()), SLOT(slotClipText()));

    ui->statusBar->addPermanentWidget(test);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PlainTextEdit_textChanged()
{
    std::string numbers[]={"O", "I", "Z", "E", "h","S","G","T","B", "P"};

    QString str=ui->PlainTextEdit->toPlainText();// String plain input text
    vector <string> poutput;// Vector for plain output message
    std::string EnOutput;
    char temp={};
    if (ui->EnToLeButton->isChecked())//Translate English to l33t
    {
        for (QChar letter:str)
        {
            temp=letter.toLatin1();

            if (isalpha(temp))
            {
                poutput.push_back(convert_alpha(temp));
                continue;
            }
            if (isdigit(temp))
            {
                poutput.push_back(numbers[letter.digitValue()]);
                continue;
            }
            if (isspace(temp))
            {
                poutput.push_back(" ");
                continue;
            }

        }
        ostringstream oss;

          if (!poutput.empty())
          {
            // Convert all but the last element to avoid a trailing ","
            copy(poutput.begin(), poutput.end()-1,
                ostream_iterator<string>(oss, ""));

            // Now add the last element with no delimiter
            oss << poutput.back();
          }
          BufClipboard=QString::fromStdString(oss.str());
          ui->LeetTextEdit->setText(QString::fromStdString(oss.str()));
    }
    if (ui->LeToEnButton->isChecked())
    {
        std::string StringBuffer=str.toStdString();
        EnOutput=l33t(StringBuffer);
        ui->LeetTextEdit->setText(QString::fromStdString(EnOutput));

    }



}
void MainWindow::slotClipText()
{


    //QString testsrting = "<Ваша строка>";
    QApplication::clipboard()->setText(BufClipboard);

    MainWindow::test->setText("String is copied");

    QTimer::singleShot(5000,test,SLOT(clear()));
    ui->statusBar->clearMessage();

}


void MainWindow::on_EnToLeButton_clicked()
{
    ui->PlainTextEdit->clear();
}

void MainWindow::on_LeToEnButton_clicked()
{
    ui->PlainTextEdit->clear();
}
