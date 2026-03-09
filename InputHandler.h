//
// Created by JanTr on 2026-01-26.
//

#ifndef CLICALCULATOR_INPUTHANDLER_H
#define CLICALCULATOR_INPUTHANDLER_H
#include <vector>


class InputHandler {
public:
    double readCurrent();
    double readPower();
    double readVoltage();
    double readResistance();
    //Resistor Pro kalkyl
    int availableResistor();
    std::vector<double>  getResistorValues(int count);

};


#endif //CLICALCULATOR_INPUTHANDLER_H