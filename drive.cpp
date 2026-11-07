
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

#include "drive.h"
#include "graph.h"

using namespace std;

// Select customer location
int selectDriveLocation(const vector<Location>& locations)
{
    cout << "\nSelect Your Current Location:\n";

    for (const Location& location : locations)
    {
        cout << location.id << ". " << location.name << endl;
    }

    int choice;

    cout << "Enter choice: ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(locations.size()))
        return -1;

    return choice;
}

// Select preferred cuisine
int selectDriveCuisine(const vector<Cuisine>& cuisines)
{
    cout << "\nSelect Preferred Cuisine:\n";

    for (const Cuisine& cuisine : cuisines)
    {
        cout << cuisine.id << ". " << cuisine.name << endl;
    }

    int choice;

    cout << "Enter choice: ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(cuisines.size()))
        return -1;

    return choice;
}

// Find restaurants offering selected cuisine
vector<Restaurant> findDriveRestaurants(
    const vector<Restaurant>& restaurants,
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int cuisineId)
{
    return findRestaurantsByCuisine(
        restaurants, menus, dishes, cuisineId);
}

// Calculate shortest driving distance
double calculateDriveDistance(
    int userLocationId,
    const Restaurant& restaurant)
{
    vector<Road> roads = initializeRoads();

    Graph graph(6);
    graph.buildFromRoads(roads);

    return graph.shortestDistance(
        userLocationId, restaurant.locationId);
}

// Estimate driving time in minutes
double calculateDriveTime(double distance)
{
    const double AVERAGE_SPEED = 30.0;

    return (distance / AVERAGE_SPEED) * 60.0;
}

double calculateDriveScore(
    const Restaurant& restaurant,
    double distance)
{
    double distanceScore =
        100.00 / (1.0 + distance);

    double ratingScore =
        (restaurant.rating / 5.0) * 100.0;

    return (distanceScore * 0.60) +
           (ratingScore * 0.40);
}

// Rank restaurants using selection sort
void rankDriveRestaurants(
    vector<Restaurant>& restaurants,
    int userLocationId)
{
    for (size_t i = 0; i < restaurants.size(); i++)
    {
        size_t best = i;

        double bestDistance =
            calculateDriveDistance(
                userLocationId, restaurants[i]);

        double bestScore =
            calculateDriveScore(
                restaurants[i], bestDistance);

        for (size_t j = i + 1; j < restaurants.size(); j++)
        {
            double distance =
                calculateDriveDistance(
                    userLocationId, restaurants[j]);

            double score =
                calculateDriveScore(
                    restaurants[j], distance);

            if (score > bestScore)
            {
                best = j;
                bestScore = score;
            }
        }

        swap(restaurants[i], restaurants[best]);
    }
}

// Display drive-through recommendations
void displayDriveRecommendations(
    const vector<Restaurant>& restaurants,
    int userLocationId)
{
    cout << "\n========== DRIVE-THROUGH RECOMMENDATIONS ==========\n";

    for (size_t i = 0; i < restaurants.size() && i < 3; i++)
    {
        const Restaurant& restaurant = restaurants[i];

        double distance =
            calculateDriveDistance(
                userLocationId, restaurant);

        double travelTime =
            calculateDriveTime(distance);

        double score =
            calculateDriveScore(
                restaurant, distance);

        cout << "\n" << i + 1 << ". " << restaurant.name;

        cout << "\nLocation: "
             << getLocationById(
                    initializeLocations(),
                    restaurant.locationId).name;

        cout << "\nRating: " << restaurant.rating;

        cout << "\nDriving Distance: "
             << fixed << setprecision(2)
             << distance << " km";

        cout << "\nEstimated Driving Time: "
             << travelTime << " minutes";

        cout << "\nDrive-through Score: "
             << score << "/100\n";
    }
}

// Display selected restaurant menu
void displayDriveMenu(
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int restaurantId)
{
    vector<Dish> menu =
        getRestaurantMenu(menus, dishes, restaurantId);

    cout << "\n========== RESTAURANT MENU ==========\n";

    for (const Dish& dish : menu)
    {
        cout << dish.id << ". " << dish.name
             << " - Rs. " << dish.price
             << (dish.vegetarian ? " (Veg)" : " (Non-Veg)")
             << endl;
    }
}

// Run complete drive-through module
void runDriveModule()
{
    vector<Location> locations = initializeLocations();
    vector<Restaurant> restaurants = initializeRestaurants();
    vector<Cuisine> cuisines = initializeCuisines();
    vector<Dish> dishes = initializeDishes();
    vector<Menu> menus = initializeMenus();

    cout << "\n========== SMARTBITE DRIVE-THROUGH ==========\n";

    int locationId = selectDriveLocation(locations);

    if (locationId == -1)
    {
        cout << "Invalid location!\n";
        return;
    }

    int cuisineId = selectDriveCuisine(cuisines);

    if (cuisineId == -1)
    {
        cout << "Invalid cuisine!\n";
        return;
    }

    vector<Restaurant> filteredRestaurants =
        findDriveRestaurants(
            restaurants, menus, dishes, cuisineId);

    if (filteredRestaurants.empty())
    {
        cout << "\nNo restaurants found for this cuisine.\n";
        return;
    }

    rankDriveRestaurants(filteredRestaurants, locationId);

    displayDriveRecommendations(
        filteredRestaurants, locationId);

    int choice;

    cout << "\nEnter Restaurant ID to view its menu (0 to exit): ";
    cin >> choice;

    if (choice == 0)
        return;

    Restaurant selected =
        getRestaurantById(filteredRestaurants, choice);

    if (selected.id == -1)
    {
        cout << "Invalid restaurant selection!\n";
        return;
    }

    displayDriveMenu(menus, dishes, selected.id);
}
