#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "data.h"

using namespace std;

void runOrderModule(
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int restaurantId,
    const string& serviceName
);

#endif
