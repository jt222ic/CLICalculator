#include <iostream>
#include "Calculator.h"



 // P = I*U

double Calculator::calculatePower(double voltage, double current) {
    return voltage * current;
}

double Calculator::calculateVoltage(double power, double current) {
    return power / current;
}

double Calculator::calculateCurrent(double power, double voltage) {
    return power / voltage;
}



