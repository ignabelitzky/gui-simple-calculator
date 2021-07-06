#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    statusLabel = new QLabel;
    ui->statusBar->addPermanentWidget(statusLabel);
    display = ui->display_lineEdit;
    value1 = 0;
    value2 = 0;
    operation = '\0';
    result = 0;
}

Calculator::~Calculator()
{
    delete statusLabel;
    delete ui;
}


void Calculator::on_zero_btn_clicked()
{
    QString previousText = display->text();
    display->setText(previousText + "0");
}


void Calculator::on_one_btn_clicked()
{
    QString previousText = display->text();
    display->setText(previousText + "1");
}


void Calculator::on_two_btn_clicked()
{
    QString previousText = display->text();
    display->setText(previousText + "2");
}


void Calculator::on_three_btn_clicked()
{
   QString previousText = display->text();
   display->setText(previousText + "3");
}


void Calculator::on_four_btn_clicked()
{
   QString previousText = display->text();
   display->setText(previousText + "4");
}


void Calculator::on_five_btn_clicked()
{
   QString previousText = display->text();
   display->setText(previousText + "5");

}


void Calculator::on_six_btn_clicked()
{
   QString previousText = display->text();
   display->setText(previousText + "6");
}


void Calculator::on_seven_btn_clicked()
{
   QString previousText = display->text();
   display->setText(previousText + "7");
}


void Calculator::on_eight_btn_clicked()
{
   QString previousText = display->text();
   display->setText(previousText + "8");
}


void Calculator::on_nine_btn_clicked()
{
   QString previousText = display->text();
   display->setText(previousText + "9");
}

void Calculator::on_comma_btn_clicked()
{
   QString previousText = display->text();
   display->setText(previousText + ".");
}

void Calculator::on_clear_btn_clicked()
{
   display->setText("");
}

void Calculator::on_divide_btn_clicked()
{
    value1 = display->text().toDouble();
    operation = '/';
    display->setText("");
}


void Calculator::on_product_btn_clicked()
{
    value1 = display->text().toDouble();
    operation = '*';
    display->setText("");
}


void Calculator::on_subtract_btn_clicked()
{
    value1 = display->text().toDouble();
    operation = '-';
    display->setText("");
}


void Calculator::on_sum_btn_clicked()
{
    value1 = display->text().toDouble();
    operation = '+';
    display->setText("");
}


void Calculator::on_equal_btn_clicked()
{
    value2 = display->text().toDouble();
    switch(operation) {
    case '+':
        result = value1 + value2;
        break;
    case '-':
        result = value1 - value2;
        break;
    case '*':
        result = value1 * value2;
        break;
    case '/':
        result = value1 / value2;
        break;
    case '%':
        result = (static_cast<int>(value1)) % (static_cast<int>(value2));
        break;
    default:
        qDebug() << "Invalid operation";
        break;
    }
    display->setText(QString::number(result));
    statusLabel->setText(QString::number(value1) + operation + QString::number(value2));
}


void Calculator::on_backspace_btn_clicked()
{
    qsizetype lengthText = display->text().length();
   if(lengthText > 0) {
       QString newText = display->text().first(lengthText - 1);
       display->setText(newText);
   }
}




void Calculator::on_mod_btn_clicked()
{
   value1 = display->text().toDouble();
   operation = '%';
   display->setText("");
}

