#include "chip.h"

Chip::Chip() : count(0) {}

Chip::~Chip() {
    cout << "Об’єкт Chip знищено.\n";
}

void Chip::inputData() {
    cout << "Скільки мікросхем хочете ввести (макс 5)? ";
    while (!(cin >> count) || count <= 0 || count > 5) {
        cout << "❌ Некоректне значення! Введіть число від 1 до 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    for (int i = 0; i < count; i++) {
        cout << "\nМікросхема №" << i + 1 << ":\n";

        // ===== Назва =====
        do {
            cout << "Назва: ";
            getline(cin, chips[i].name);
            if (chips[i].name.empty()) {
                cout << "❌ Назва не може бути порожньою! Повторіть.\n";
            }
        } while (chips[i].name.empty());

        // ===== Кількість виводів =====
        cout << "Кількість виводів: ";
        while (!(cin >> chips[i].pins) || chips[i].pins <= 0) {
            cout << "❌ Введіть коректне число ніжок (> 0): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // ===== Напруга =====
        cout << "Напруга живлення (V): ";
        while (!(cin >> chips[i].voltage) || chips[i].voltage <= 0.0) {
            cout << "❌ Введіть коректну напругу (> 0): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (chips[i].voltage >= v) {
            cout << chips[i].name << " (" << chips[i].voltage << "V)\n";
            found = true;
        }
    }
    if (!found)
        cout << "Не знайдено мікросхем з такою напругою.\n";
}

void Chip::showByPins(int p) const {
    cout << "\n=== Мікросхеми з кількістю виводів >= " << p << " ===\n";
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (chips[i].pins >= p) {
            cout << chips[i].name << " (" << chips[i].pins << " ніжок)\n";
            found = true;
        }
    }
    if (!found)
        cout << "Не знайдено мікросхем з такою кількістю виводів.\n";
}
