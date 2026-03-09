//
// Created by JanTr on 2026-01-26.
//
#include <iostream>
#include "InputHandler.h"

#include <vector>


// P =POWER(effekt watt) U= Ubelbecht (Volt difference) I=Interpre courant(current) R=reistance(Ohm)

double InputHandler:: readVoltage() {
    double voltage;
    std::cout << "Ange spänning (V): ";
    std::cin >> voltage;
    if (voltage < 0.0) {
        throw std::invalid_argument("Voltage must be greater than 0");
    }
    return voltage;
}
double InputHandler:: readCurrent() {
    double current;
    int unit;
    std::cout << "Ange Ström: ";
    std::cin >> current;
    std::cout << "Är strömmen i (1) Ampere eller (2) Milliampere? ";
    std::cin >> unit;

    if (unit == 2) {
        current /= 1000.0;
    }

    return current;
}
double InputHandler:: readResistance() {
    double resistance;
    std::cout << "Ange Motstånd: ";
    std::cin >> resistance;

    return resistance;
}

double InputHandler::readPower() {
    double power;
    std::cout << "Ange Effekt (W): ";
    std::cin >> power;
    return power;
}

// pro resistor Kalkylator
int InputHandler::availableResistor() {
    double resistance;
    std::cout <<"Ange hur många Tillgängliga Resistor (R): ";
    std::cin >>resistance;
    return resistance;
}
// tillämpning av vector d.v.s array , chatgpt föredrar moderna vector uträkning en vanliga arays
// ingen fixerat minne d.v.s du behöver inte bestämma minnes utrymme. som int numbers[totala mängden];
// med raw arrays måste det frigöras med delete eller någonting

std::vector<double> InputHandler::getResistorValues(int count) {
    std::vector<double> resistors(count);

    //loopa igenom count för att sätta in för varje vector eller array
    for (int i = 0; i < count; i++) {
        std::cout << "Värde resistor " << i + 1 << " (Ohm): ";
        std::cin >> resistors[i];
    }
    return resistors;
}