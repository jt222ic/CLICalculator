//
// Created by JanTr on 2026-01-29.
//

#include "ResProCalculator.h"

#include <vector>


double ResProCalculator:: calculateSeries(const std::vector<double>& resistors) {
    double sum = 0.0;
    for (double r : resistors) {
        sum += r;
    }
    return sum;
}

double ResProCalculator::calculateParallel(const std::vector<double>& resistors) {
    double sum = 0.0;
    for (double r : resistors) {
        sum += 1.0 / r;
    }
    return 1.0 / sum;
}

double ResProCalculator::TotalCurrent(double voltage, double TotalResistor) {

    return voltage/TotalResistor;;
}
double ResProCalculator::TotalEffect(double current, double TotalResistor) {
    return current*current*TotalResistor;
}
