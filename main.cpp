#include "RouteManager.h"
#include <iostream>

int main() {
    RouteManager manager;
    int choice;

    do {
        std::cout << "\n1. Добавить маршрут"
                  << "\n2. Удалить маршрут"
                  << "\n3. Редактировать маршрут"
                  << "\n4. Показать все маршруты"
                  << "\n5. Найти по номеру"
                  << "\n0. Выход\nВыбор: ";
        std::cin >> choice;

        try {
            if (choice == 1) {
                Route r;
                std::cin >> r;
                int pos;
                std::cout << "Позиция вставки: ";
                std::cin >> pos;
                manager.add(r, pos);
            }
            else if (choice == 2) {
                int pos;
                std::cout << "Позиция удаления: ";
                std::cin >> pos;
                manager.remove(pos);
            }
            else if (choice == 3) {
                int pos;
                std::cout << "Позиция редактирования: ";
                std::cin >> pos;
                manager.edit(pos);
            }
            else if (choice == 4) {
                manager.showAll();
            }
            else if (choice == 5) {
                int num;
                std::cout << "Введите номер маршрута: ";
                std::cin >> num;
                manager.findByNumber(num);
            }
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }

    } while (choice != 0);

    return 0;
}
