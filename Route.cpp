#include "Route.h"
#include <stdexcept>

Route::Route() : start(""), end(""), number(0) {
    std::cout << "Route: вызван конструктор без параметров\n";
}

Route::Route(const std::string& s, const std::string& e, int n)
    : start(s), end(e), number(n) {
    std::cout << "Route: вызван конструктор с параметрами\n";
}

Route::Route(const Route& other)
    : start(other.start), end(other.end), number(other.number) {
    std::cout << "Route: вызван конструктор копирования\n";
}

Route::~Route() {
    std::cout << "Route: вызван деструктор (маршрут №" << number << ")\n";
}

void Route::setStart(const std::string& s) { start = s; }
void Route::setEnd(const std::string& e) { end = e; }

void Route::setNumber(int n) {
    if (n < 0)
        throw std::invalid_argument("Номер маршрута не может быть отрицательным");
    number = n;
}

std::string Route::getStart() const { return start; }
std::string Route::getEnd() const { return end; }
int Route::getNumber() const { return number; }

std::ostream& operator<<(std::ostream& out, const Route& r) {
    out << "Маршрут №" << r.number
        << " | " << r.start << " -> " << r.end;
    return out;
}

std::istream& operator>>(std::istream& in, Route& r) {
    std::cout << "Начальный пункт: ";
    in >> r.start;
    std::cout << "Конечный пункт: ";
    in >> r.end;
    std::cout << "Номер маршрута: ";
    in >> r.number;
    return in;
}
