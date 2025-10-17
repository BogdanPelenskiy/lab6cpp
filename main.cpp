#include "chip.h"

int main() {
    Chip c;
    c.inputData();
    c.displayData();
    c.showByVoltage(5.0);
    c.showByPins(8);
    return 0;
}
