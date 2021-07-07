#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void on_zero_btn_clicked();

    void on_one_btn_clicked();

    void on_two_btn_clicked();

    void on_three_btn_clicked();

    void on_four_btn_clicked();

    void on_five_btn_clicked();

    void on_six_btn_clicked();

    void on_seven_btn_clicked();

    void on_eight_btn_clicked();

    void on_nine_btn_clicked();

    void on_clear_btn_clicked();

    void on_divide_btn_clicked();

    void on_product_btn_clicked();

    void on_subtract_btn_clicked();

    void on_sum_btn_clicked();

    void on_equal_btn_clicked();

    void on_backspace_btn_clicked();

    void on_comma_btn_clicked();

    void on_mod_btn_clicked();

private:
    Ui::Calculator *ui;
    QLineEdit *display;
    QLabel *statusLabel;
    double firstValue;
    double secondValue;
    double result;
    char operation;

};
#endif // CALCULATOR_H
