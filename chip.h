#ifndef CHIP_H
#define CHIP_H

#include <array>
#include <string>
#include <iostream>
using namespace std;

struct ChipData {
    string name;
    int pins;
    double voltage;
};

class Chip {
private:
    static const int SIZE = 5;
    array<ChipData, SIZE> chips;
    int count;

public:
    Chip();
    ~Chip();

    void inputData();
    void displayData() const;
    void showByVoltage(double v) const;
    void showByPins(int p) const;
};

#endif
