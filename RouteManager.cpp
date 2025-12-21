#include "RouteManager.h"
#include <iostream>
#include <stdexcept>

RouteManager::RouteManager() : routes(nullptr), size(0) {
    std::cout << "RouteManager создан\n";
}

RouteManager::~RouteManager() {
    delete[] routes;
    std::cout << "RouteManager уничтожен\n";
}

void RouteManager::sort() {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (routes[j].getNumber() > routes[j + 1].getNumber())
                std::swap(routes[j], routes[j + 1]);
}

void RouteManager::add(Route r, int pos) {
    if (pos < 0 || pos > size)
        throw std::out_of_range("Некорректная позиция вставки");

    Route* temp = new Route[size + 1];

    for (int i = 0; i < pos; ++i)
        temp[i] = routes[i];

    temp[pos] = r;

    for (int i = pos; i < size; ++i)
        temp[i + 1] = routes[i];

    delete[] routes;
    routes = temp;
    size++;

    sort();
}

void RouteManager::remove(int pos) {
    if (pos < 0 || pos >= size)
        throw std::out_of_range("Некорректная позиция удаления");

    Route* temp = new Route[size - 1];

    for (int i = 0, j = 0; i < size; ++i)
        if (i != pos)
            temp[j++] = routes[i];

    delete[] routes;
    routes = temp;
    size--;
}

void RouteManager::edit(int pos) {
    if (pos < 0 || pos >= size)
        throw std::out_of_range("Некорректная позиция редактирования");

    std::cin >> routes[pos];
    sort();
}

void RouteManager::showAll() const {
    for (int i = 0; i < size; ++i)
        std::cout << i << ": " << routes[i] << "\n";
}

void RouteManager::findByNumber(int number) const {
    bool found = false;
    for (int i = 0; i < size; ++i)
        if (routes[i].getNumber() == number) {
            std::cout << routes[i] << "\n";
            found = true;
        }

    if (!found)
        std::cout << "Маршрут с таким номером не найден\n";
}
