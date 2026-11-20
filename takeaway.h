#ifndef TAKEAWAY_H
#define TAKEAWAY_H

#include <vector>
#include "data.h"

using namespace std;

// Select customer location
int selectTakeawayLocation(const vector<Location>& locations);

// Select preferred cuisine
int selectTakeawayCuisine(const vector<Cuisine>& cuisines);

// Find restaurants offering selected cuisine
vector<Restaurant> findTakeawayRestaurants(
    const vector<Restaurant>& restaurants,
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int cuisineId
);

// Calculate travel distance
double calculateTakeawayDistance(
    int userLocationId,
    const Restaurant& restaurant
);

// Estimate travel time
double calculateTakeawayTravelTime(double distance);

// Calculate takeaway recommendation score
double calculateTakeawayScore(
    const Restaurant& restaurant,
    double travelTime
);

// Rank restaurants
void rankTakeawayRestaurants(
    vector<Restaurant>& restaurants,
    int userLocationId
);

// Display recommendations
void displayTakeawayRecommendations(
    const vector<Restaurant>& restaurants,
    int userLocationId
);

// Display restaurant menu
void displayTakeawayMenu(
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int restaurantId
);

// Run complete takeaway module
void runTakeawayModule();

#endif
