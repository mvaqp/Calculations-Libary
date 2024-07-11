#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QWidget {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

    private slots:
        void onDigitPressed();
    void onOperatorPressed();
    void onEqualPressed();
    void onClearPressed();

private:
    Ui::Calculator *ui;
    double firstNum;
    bool userIsTypingSecondNumber;
};

#endif // CALCULATOR_H
