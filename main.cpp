//
// Created by Matt White on 11/07/2024.
//
#include <QApplication>
#include "calculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Calculator calculator;
    calculator.show();
    return app.exec();
}

