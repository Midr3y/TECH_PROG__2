#include <iostream>
#include <clocale>
#include <windows.h>

#include "RouteManager.h"
#include "TextProcessor.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    RouteManager routeManager;
    int choice;

    do {
        std::cout << "\n====== ГЛАВНОЕ МЕНЮ ======\n";
        std::cout << "1. Работа с маршрутами (ROUTE)\n";
        std::cout << "2. Работа с текстовым файлом\n";
        std::cout << "0. Выход\n";
        std::cout << "Выбор: ";
        std::cin >> choice;

        try {
            if (choice == 1) {
                int sub;
                do {
                    std::cout << "\n--- МЕНЮ МАРШРУТОВ ---\n";
                    std::cout << "1. Добавить маршрут\n";
                    std::cout << "2. Удалить маршрут\n";
                    std::cout << "3. Редактировать маршрут\n";
                    std::cout << "4. Показать все маршруты\n";
                    std::cout << "5. Найти маршрут по номеру\n";
                    std::cout << "0. Назад\n";
                    std::cout << "Выбор: ";
                    std::cin >> sub;

                    if (sub == 1) {
                        Route r;
                        std::cin >> r;
                        int pos;
                        std::cout << "Позиция вставки: ";
                        std::cin >> pos;
                        routeManager.add(r, pos);
                    }
                    else if (sub == 2) {
                        int pos;
                        std::cout << "Позиция удаления: ";
                        std::cin >> pos;
                        routeManager.remove(pos);
                    }
                    else if (sub == 3) {
                        int pos;
                        std::cout << "Позиция редактирования: ";
                        std::cin >> pos;
                        routeManager.edit(pos);
                    }
                    else if (sub == 4) {
                        routeManager.showAll();
                    }
                    else if (sub == 5) {
                        int num;
                        std::cout << "Введите номер маршрута: ";
                        std::cin >> num;
                        routeManager.findByNumber(num);
                    }

                } while (sub != 0);
            }
            else if (choice == 2) {
                std::string filename;
                std::cout << "Введите имя файла: ";
                std::cin >> filename;

                TextProcessor tp(filename);
                std::cout << "\nСлова, начинающиеся и заканчивающиеся гласными:\n";
                tp.processFile();
            }
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

    } while (choice != 0);

    return 0;
}
