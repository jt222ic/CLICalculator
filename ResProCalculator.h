//
// Created by JanTr on 2026-01-29.
//

#ifndef CLICALCULATOR_RESPROCALCULATOR_H
#define CLICALCULATOR_RESPROCALCULATOR_H
#include <vector>


class ResProCalculator {
public:
    double calculateSeries(const std::vector<double> &resistorValues);
    double calculateParallel(const std::vector<double>& resistorValues);

    double TotalCurrent(double voltage, double TotalResistor);
    double TotalEffect(double current, double TotalResistor);
};


#endif //CLICALCULATOR_RESPROCALCULATOR_H