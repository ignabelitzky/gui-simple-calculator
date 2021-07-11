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
    firstValue = 0;
    secondValue = 0;
    operation = '\0';
    result = 0;
}

Calculator::~Calculator()
{
    delete statusLabel;
    delete ui;
}

void Calculator::keyPressEvent(QKeyEvent *e) {
    int keyPressed = e->key();
    switch(keyPressed) {
    case Qt::Key_0:
        on_zero_btn_clicked();
        break;
    case Qt::Key_1:
        on_one_btn_clicked();
        break;
    case Qt::Key_2:
        on_two_btn_clicked();
        break;
    case Qt::Key_3:
        on_three_btn_clicked();
        break;
    case Qt::Key_4:
        on_four_btn_clicked();
        break;
    case Qt::Key_5:
        on_five_btn_clicked();
        break;
    case Qt::Key_6:
        on_six_btn_clicked();
        break;
    case Qt::Key_7:
        on_seven_btn_clicked();
        break;
    case Qt::Key_8:
        on_eight_btn_clicked();
        break;
    case Qt::Key_9:
        on_nine_btn_clicked();
        break;
    case Qt::Key_Equal:
        on_equal_btn_clicked();
        break;
    case Qt::Key_Comma:
        on_comma_btn_clicked();
        break;
    case Qt::Key_Period:
        on_comma_btn_clicked();
        break;
    case Qt::Key_Plus:
        on_sum_btn_clicked();
        break;
    case Qt::Key_Minus:
        on_subtract_btn_clicked();
        break;
    case Qt::Key_Asterisk:
        on_product_btn_clicked();
        break;
    case Qt::Key_Slash:
        on_divide_btn_clicked();
        break;
    case Qt::Key_Percent:
        on_mod_btn_clicked();
        break;
    case Qt::Key_Delete:
        on_clear_btn_clicked();
        break;
    case Qt::Key_Backspace:
        on_backspace_btn_clicked();
        break;
    case Qt::Key_Return:
        on_equal_btn_clicked();
        break;
    case Qt::Key_Enter:
        on_equal_btn_clicked();
        break;
    default:
        break;
    }
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
    firstValue = 0;
    secondValue = 0;
    result = 0;
    display->setText("");
    statusLabel->setText("");
}

void Calculator::on_divide_btn_clicked()
{
    statusLabel->setText(display->text());
    firstValue = display->text().toDouble();
    operation = '/';
    display->setText("");
}


void Calculator::on_product_btn_clicked()
{
    statusLabel->setText(display->text());
    firstValue= display->text().toDouble();
    operation = '*';
    display->setText("");
}


void Calculator::on_subtract_btn_clicked()
{
    if(display->text().isEmpty()) {
        display->setText("-");
    } else {
        statusLabel->setText(display->text());
        firstValue = display->text().toDouble();
        operation = '-';
        display->setText("");
    }
}


void Calculator::on_sum_btn_clicked()
{
    if(display->text().isEmpty()) {
        display->setText("+");
    } else {
        statusLabel->setText(display->text());
        firstValue = display->text().toDouble();
        operation = '+';
        display->setText("");
    }
}


void Calculator::on_equal_btn_clicked()
{
    secondValue = display->text().toDouble();
    switch(operation) {
    case '+':
        result = firstValue + secondValue;
        break;
    case '-':
        result = firstValue - secondValue;
        break;
    case '*':
        result = firstValue* secondValue;
        break;
    case '/':
        result = firstValue / secondValue;
        break;
    case '%':
        result = (static_cast<int>(firstValue)) % (static_cast<int>(secondValue));
        break;
    default:
        break;
    }
    display->setText(QString::number(result));
    statusLabel->setText(QString::number(firstValue) + operation + QString::number(secondValue));
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
    statusLabel->setText(display->text());
    firstValue = display->text().toDouble();
    operation = '%';
    display->setText("");
}

void Calculator::on_negative_btn_clicked()
{
    double_t displayValue = display->text().toDouble();
    displayValue = -displayValue;
    display->setText(QString::number(displayValue));
}

