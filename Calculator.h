//
// Created by JanTr on 2026-01-19.
//

#ifndef CLICALCULATOR_CALCULATOR_H
#define CLICALCULATOR_CALCULATOR_H


class Calculator {
public:
    double calculatePower(double voltage, double current);
    double calculateCurrent(double power, double voltage);
    double calculateVoltage(double power, double current);
};


#endif //CLICALCULATOR_CALCULATOR_H