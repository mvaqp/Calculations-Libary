#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent), ui(new Ui::Calculator) {
    ui->setupUi(this);

    connect(ui->button0, SIGNAL(released()), this, SLOT(onDigitPressed()));
    connect(ui->button1, SIGNAL(released()), this, SLOT(onDigitPressed()));
    connect(ui->button2, SIGNAL(released()), this, SLOT(onDigitPressed()));
    connect(ui->button3, SIGNAL(released()), this, SLOT(onDigitPressed()));
    connect(ui->button4, SIGNAL(released()), this, SLOT(onDigitPressed()));
    connect(ui->button5, SIGNAL(released()), this, SLOT(onDigitPressed()));
    connect(ui->button6, SIGNAL(released()), this, SLOT(onDigitPressed()));
    connect(ui->button7, SIGNAL(released()), this, SLOT(onDigitPressed()));
    connect(ui->button8, SIGNAL(released()), this, SLOT(onDigitPressed()));
    connect(ui->button9, SIGNAL(released()), this, SLOT(onDigitPressed()));

    connect(ui->buttonPlus, SIGNAL(released()), this, SLOT(onOperatorPressed()));
    connect(ui->buttonMinus, SIGNAL(released()), this, SLOT(onOperatorPressed()));
    connect(ui->buttonMultiply, SIGNAL(released()), this, SLOT(onOperatorPressed()));
    connect(ui->buttonDivide, SIGNAL(released()), this, SLOT(onOperatorPressed()));

    connect(ui->buttonEquals, SIGNAL(released()), this, SLOT(onEqualPressed()));
    connect(ui->buttonClear, SIGNAL(released()), this, SLOT(onClearPressed()));
}

Calculator::~Calculator() {
    delete ui;
}

void Calculator::onDigitPressed() {
    QPushButton *button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if ((ui->buttonPlus->isChecked() || ui->buttonMinus->isChecked() ||
         ui->buttonMultiply->isChecked() || ui->buttonDivide->isChecked()) && (!userIsTypingSecondNumber)) {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber, 'g', 15);
    } else {
        if (ui->display->text().contains('.') && button->text() == "0") {
            newLabel = ui->display->text() + button->text();
        } else {
            labelNumber = (ui->display->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber, 'g', 15);
        }
    }

    ui->display->setText(newLabel);
}

void Calculator::onOperatorPressed() {
    QPushButton *button = (QPushButton*)sender();
    firstNum = ui->display->text().toDouble();
    button->setChecked(true);
}

void Calculator::onEqualPressed() {
    double labelNumber, secondNum;
    QString newLabel;
    secondNum = ui->display->text().toDouble();

    if (ui->buttonPlus->isChecked()) {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->display->setText(newLabel);
        ui->buttonPlus->setChecked(false);
    } else if (ui->buttonMinus->isChecked()) {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->display->setText(newLabel);
        ui->buttonMinus->setChecked(false);
    } else if (ui->buttonMultiply->isChecked()) {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->display->setText(newLabel);
        ui->buttonMultiply->setChecked(false);
    } else if (ui->buttonDivide->isChecked()) {
        if (secondNum == 0) {
            ui->display->setText("Error");
        } else {
            labelNumber = firstNum / secondNum;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->display->setText(newLabel);
        }
        ui->buttonDivide->setChecked(false);
    }
    userIsTypingSecondNumber = false;
}

void Calculator::onClearPressed() {
    ui->buttonPlus->setChecked(false);
    ui->buttonMinus->setChecked(false);
    ui->buttonMultiply->setChecked(false);
    ui->buttonDivide->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->display->setText("0");
}
