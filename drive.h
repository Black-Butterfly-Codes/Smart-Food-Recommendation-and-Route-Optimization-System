
#ifndef DRIVE_H
#define DRIVE_H

#include <vector>
#include "data.h"

using namespace std;

// Select customer location
int selectDriveLocation(const vector<Location>& locations);

// Select preferred cuisine
int selectDriveCuisine(const vector<Cuisine>& cuisines);

// Find restaurants offering selected cuisine
vector<Restaurant> findDriveRestaurants(
    const vector<Restaurant>& restaurants,
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int cuisineId
);

// Calculate driving distance
double calculateDriveDistance(
    int userLocationId,
    const Restaurant& restaurant
);

// Calculate estimated driving time
double calculateDriveTime(double distance);

// Calculate recommendation score
double calculateDriveScore(
    const Restaurant& restaurant,
    double distance
);

// Rank restaurants
void rankDriveRestaurants(
    vector<Restaurant>& restaurants,
    int userLocationId
);

// Display recommendations
void displayDriveRecommendations(
    const vector<Restaurant>& restaurants,
    int userLocationId
);

// Display restaurant menu
void displayDriveMenu(
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int restaurantId
);

// Run complete drive-through module
void runDriveModule();

#endif
