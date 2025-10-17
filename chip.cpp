#include "chip.h"

Chip::Chip() : count(0) {}

Chip::~Chip() {
    cout << "Об’єкт Chip знищено.\n";
}

void Chip::inputData() {
    cout << "Скільки мікросхем хочете ввести (макс 5)? ";
    cin >> count;
    if (count > 5) count = 5;
    cin.ignore();

    for (int i = 0; i < count; i++) {
        cout << "\nМікросхема №" << i + 1 << ":\n";
        cout << "Назва: ";
        getline(cin, chips[i].name);
        cout << "Кількість виводів: ";
        cin >> chips[i].pins;
        cout << "Напруга живлення (V): ";
        cin >> chips[i].voltage;
        cin.ignore();
    }
}

void Chip::displayData() const {
    cout << "\n=== Усі мікросхеми ===\n";
    for (int i = 0; i < count; i++) {
        cout << "Назва: " << chips[i].name
             << " | Виводи: " << chips[i].pins
             << " | Напруга: " << chips[i].voltage << "V\n";
    }
}

void Chip::showByVoltage(double v) const {
    cout << "\n=== Мікросхеми з напругою >= " << v << "V ===\n";
    for (int i = 0; i < count; i++) {
        if (chips[i].voltage >= v)
            cout << chips[i].name << " (" << chips[i].voltage << "V)\n";
    }
}

void Chip::showByPins(int p) const {
    cout << "\n=== Мікросхеми з кількістю виводів >= " << p << " ===\n";
    for (int i = 0; i < count; i++) {
        if (chips[i].pins >= p)
            cout << chips[i].name << " (" << chips[i].pins << " ніжок)\n";
    }
}
