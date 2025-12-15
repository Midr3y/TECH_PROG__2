#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string>

class Route {
private:
    std::string start;
    std::string end;
    int number;

public:
    Route();
    Route(const std::string& s, const std::string& e, int n);
    Route(const Route& other);
    ~Route();

    void setStart(const std::string& s);
    void setEnd(const std::string& e);
    void setNumber(int n);

    std::string getStart() const;
    std::string getEnd() const;
    int getNumber() const;

    friend std::ostream& operator<<(std::ostream& out, const Route& r);
    friend std::istream& operator>>(std::istream& in, Route& r);
};

#endif
