//
// Created by JanTr on 2026-01-25.
//

#ifndef CLICALCULATOR_OHMCALCULATOR_H
#define CLICALCULATOR_OHMCALCULATOR_H


class OhmCalculator {
public:
    double calculateVoltage(double current, double resistance);
    double calculatePower(double current, double resistance);
    double calculateResistance(double power, double current);
    double calculateCurrent(double power, double resistance);
};


#endif //CLICALCULATOR_OHMCALCULATOR_H