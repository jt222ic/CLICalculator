//
// Created by JanTr on 2026-01-25.
//

#include "OhmCalculator.h"
#include <iostream>
#include <cmath>

//  U = I*R

double OhmCalculator::calculateVoltage(double current, double resistance) {

    return current*resistance;
}

double OhmCalculator::calculateCurrent(double power, double resistance) {

    return std::sqrt(power / resistance);
}

double OhmCalculator::calculateResistance(double power, double current) {
    return power / (current * current);
}


