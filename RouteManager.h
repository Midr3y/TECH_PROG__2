#ifndef ROUTEMANAGER_H
#define ROUTEMANAGER_H

#include "Route.h"

class RouteManager {
private:
    Route* routes;
    int size;

    void sort();

public:
    RouteManager();
    ~RouteManager();

    void add(Route r, int pos);
    void remove(int pos);
    void edit(int pos);
    void showAll() const;
    void findByNumber(int number) const;
};

#endif
