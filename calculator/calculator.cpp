#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    display = ui->display_lineEdit;
    value1 = 0;
    value2 = 0;
    operation = '\0';
    result = 0;
}

Calculator::~Calculator()
{
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
    default:
        qDebug() << "Invalid operation";
        break;
    }
    display->setText(QString::number(result));
}

