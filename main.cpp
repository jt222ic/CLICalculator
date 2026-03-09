#include <iostream>
#include "Calculator.h"
#include "OhmCalculator.h"
#include "InputHandler.h"
#include <fstream>
#include <iomanip>
#include <vector>

#include "ResProCalculator.h"

Calculator calc;
OhmCalculator Ohmcalc;
InputHandler input;
ResProCalculator ResPro;
void skriva(const std::string & text, char answer,std::ofstream& out) {
    static int i;
    i++;
    out<<"RAD "<<i<<" :"<<text<<": "<<answer<<"\n";
}
void lasa() {
    std::ifstream in("../skriva.txt");
    std::string line;

    if (in.is_open()) {
        while (std::getline(in,line)) {
            std::cout<<line<<std::endl;
        }
        in.close();
    }
}
void CLI_calculator() {
    std::cout << "Välkommen till El-Kalkylatorn!" << std::endl;
    std::cout << "1. Beräkna Effekt (P)" << std::endl;
    std::cout << "2. Beräkna Spänning (U)" << std::endl;
    std::cout << "3. Beräkna Ström (I)" << std::endl;

    std::string choice;

    std::cout << "Inmatning här: ";
    std::cin >> choice;
    if (choice == "1") {
        std::cout << "Du valde 1" << std::endl;

        double voltage = input.readVoltage();
        double current = input.readCurrent();
        double Calculate_Power = calc.calculatePower(voltage,current);
        std::cout << "Resultat: Effekten är " << Calculate_Power << " Watt" << std::endl;
    }
    else if (choice == "2") {
        std::cout << "Du valde 2" << std::endl;

        double power = input.readPower();
        double current = input.readCurrent();
        double Calculate_Voltage = calc.calculateVoltage(power,current);
        std::cout << "Resultat: Spänningen är " << Calculate_Voltage << " Volt" << std::endl;

    }
    else if (choice == "3") {
        std::cout << "Du valde 3" << std::endl;

        double power = input.readPower();
        double voltage = input.readVoltage();
        double current = calc.calculateCurrent(power, voltage);

        std::cout << "Resultat: Strömmen är " << current << " Ampere" << std::endl;
    }
    else {
        std::cout << "Ogiltig svar" << std::endl;
    }
}
void showchecklista() {
    std::cout << "--- Industriell Säkerhetskontroll ---"<<std::endl;

    std::string name, object;
    std::cout << "Teknikers namn?: ";
    std::cin >> name;

    std::cout << "Arbetsobjekt?: ";
    std::cin >> object;

    std::cout << "Teknikers namn: " << name << std::endl;
    std::cout << "Arbetsobjekt: " << object << std::endl;

    struct Question {
        std::string text;
        bool critical;
    };
    std::vector<Question> questions = {
        {"Är huvudbrytaren låst (LOTO)?", true},
        {"Har spänningslöshet verifierats?", true},
        {"Använder du 1000V-isolerade verktyg?", false},
        {"Är området avspärrat?", false},
        {"Är personlig skyddsutrustning korrekt påsatt?", false}
    };
    char answer;
    std::ofstream out("../skriva.txt");
    if (!out.is_open()) {
        std::cout << "små problem"<< std::endl;
    }
    out << "Teknikers namn: " << name << "\n";
    out << "Arbetsobjekt: " << object << "\n";
    out << "-------------------------\n";

    for (size_t i = 0; i < questions.size(); ++i) {
        std::cout << i + 1 << ". " << questions[i].text << " (j/n): ";
        std::cin >> answer;
        if (questions[i].critical && answer == 'n') {
            std::cout << "STOPP! Utför åtgärden innan du fortsätter."<<std::endl;
        }
        skriva(questions[i].text,answer,out);
    }
    out.close();
}
void Ohm_calculator() {
    std::cout << "--- Ohm-Kalkylator PRO --" << std::endl;
    std::cout << "Vad vill du beräkna?" << std::endl;
    std::cout << "1. Spänning (U)" << std::endl;
    std::cout << "2. Ström (I)" << std::endl;
    std::cout << "3. Resistans (R)" << std::endl;

    std::string choice;

    std::cout << "Inmatning här: ";
    std::cin >> choice;

    if (choice == "1") {
        std::cout << "Du valde 1" << std::endl;
        double current = input.readCurrent();
        double resistance = input.readResistance();

        double Calculate_Voltage = Ohmcalc.calculateVoltage(current, resistance);

        double Calculate_Power = calc.calculatePower(Calculate_Voltage, current);
        std::cout << "Resultat: Spänningen är " << Calculate_Voltage << " V" << std::endl;
        std::cout << "Bonus: Effekten är " << Calculate_Power << " Watt" << std::endl;
    }
    if (choice == "2") {
        std::cout << "Du valde 2" << std::endl;
        double voltage = input.readVoltage();
        double resistance = input.readResistance();
        double Calculate_Current = Ohmcalc.calculateCurrent(voltage, resistance);
        double Calculate_Power = calc.calculatePower(voltage, Calculate_Current);


        // be able to achieve 2 decimals
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::fixed << std::setprecision(2);

        std::cout << "Resultat: Strömmen är " << Calculate_Current << " A" << "("<<Calculate_Current*1000.0<<")"<< std::endl;
        std::cout << "Bonus: Effekten är " << Calculate_Power << " W" << std::endl;

    }
    if (choice == "3") {

        double voltage = input.readVoltage();
        double current = input.readCurrent();
        double resistance = Ohmcalc.calculateResistance(voltage, current);
        double power = calc.calculatePower(voltage, current);

        std::cout << "Resultat: Motstånd är " << resistance << " Ohm" << std::endl;
        std::cout << "Bonus: Effekten är " << power << " W" << std::endl;
    }


}
void Resistans_calculator() {
    std::cout << "--- Resistans-kalkylator PRO --" << std::endl;
    std::cout << "1. Seriekoppling"<< std::endl;
    std::cout << "2. Parallellkoppling"<< std::endl;

    std::string choice;
    std::cout << "Inmatning här: ";
    std::cin>>choice;
    //double result;
    if (choice == "1") {
        std::cout << "Du valde 1" << std::endl;
        int count = input.availableResistor();
        std::vector<double> Resistorvalues = input.getResistorValues(count);
        double TotalSerieResistance = ResPro.calculateSeries(Resistorvalues);
        std::cout << "Resultat :Total serialresistans:: "<< TotalSerieResistance<<"Ohm"<<std::endl;
         double voltage = input.readVoltage();

        double Total_current = ResPro.TotalCurrent(voltage,TotalSerieResistance); // vvet inte vart jag ska sätta i klass
        std::cout << "Total ström: "<< Total_current << std::endl;

        double effect = ResPro.TotalEffect(Total_current, TotalSerieResistance);

        std::cout << "Total effekt: "<< effect << std::endl;

    }
    if (choice == "2") {
        std::cout << "Du valde 2" << std::endl;
        int count = input.availableResistor();
        std::vector<double> Resistorvalues = input.getResistorValues(count);

        // R total
        double Total_Resistor = ResPro.calculateParallel(Resistorvalues);
        std::cout << "Resultat :Total ersättningsresistans:: "<< Total_Resistor<< "ohm" << std::endl;
        double voltage = input.readVoltage();

        double Total_current = ResPro.TotalCurrent(voltage,Total_Resistor); // vvet inte vart jag ska sätta i klass
        std::cout << "Total ström: "<< Total_current << std::endl;

        double effect = ResPro.TotalEffect(Total_current, Total_Resistor);

        std::cout << "Total effekt: "<< effect << std::endl;
    }
}
std::string MainMenu()
{
    std::string choice;
    std::cout << "Välkommen till El!" << std::endl;
    std::cout << "Meny val här: "<< std::endl;
    std::cout << "1.Industriell Säkerhetskontroll"<<std::endl;
    std::cout << "2.CLI-Kalkylator"<<std::endl;
    std::cout << "3.OHM-Kalkylator"<<std::endl;
    std::cout << "4.Resistans-kalkylator PRO"<<std::endl;
    std::cout << "5.Visa användare och hans/hennes/henans svar"<<std::endl;
    std::cout << "Inmatning av val här: ";
    std::cin >> choice;
    return choice;
}
int main() {

    std::string choice = MainMenu();
    //säkerhetslista
    if (choice == "1") {
        showchecklista();
    }
    //CLI kalkylator
    if (choice == "2") {
        CLI_calculator();
    }
    //Ohm Kalkylator
    if (choice == "3") {
        Ohm_calculator();
    }
    //läsa fil
    if (choice == "4") {
      Resistans_calculator();
    }
    if (choice == "5") {
        lasa();
    }
    return 0;
}

