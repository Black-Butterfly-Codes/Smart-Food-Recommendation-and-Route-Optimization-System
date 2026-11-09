
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

#include "takeaway.h"
#include "graph.h"
#include "order.h"
using namespace std;

const double AVERAGE_SPEED = 30.0;

// Select customer location
int selectTakeawayLocation(const vector<Location>& locations)
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

// Select cuisine
int selectTakeawayCuisine(const vector<Cuisine>& cuisines)
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
vector<Restaurant> findTakeawayRestaurants(
    const vector<Restaurant>& restaurants,
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int cuisineId)
{
    return findRestaurantsByCuisine(
        restaurants, menus, dishes, cuisineId);
}

// Calculate shortest travel distance
double calculateTakeawayDistance(
    int userLocationId,
    const Restaurant& restaurant)
{
    vector<Road> roads = initializeRoads();

    Graph graph(6);
    graph.buildFromRoads(roads);

    return graph.shortestDistance(
        userLocationId, restaurant.locationId);
}

// Estimate travel time in minutes
double calculateTakeawayTravelTime(double distance)
{
    return (distance / AVERAGE_SPEED) * 60.0;
}

// Calculate recommendation score
double calculateTakeawayScore(
    const Restaurant& restaurant,
    double travelTime)
{
    double timeDifference =
        abs(travelTime - restaurant.preparationTime);

    double timeScore =
        100.0 / (1.0 + timeDifference);

    double ratingScore =
        (restaurant.rating / 5.0) * 100.0;

    return (timeScore * 0.60) + (ratingScore * 0.40);
}

// Rank restaurants using selection sort
void rankTakeawayRestaurants(
    vector<Restaurant>& restaurants,
    int userLocationId)
{
    for (size_t i = 0; i < restaurants.size(); i++)
    {
        size_t best = i;

        double bestTime = calculateTakeawayTravelTime(
            calculateTakeawayDistance(userLocationId, restaurants[i]));

        double bestScore =
            calculateTakeawayScore(restaurants[i], bestTime);

        for (size_t j = i + 1; j < restaurants.size(); j++)
        {
            double travelTime = calculateTakeawayTravelTime(
                calculateTakeawayDistance(userLocationId, restaurants[j]));

            double score =
                calculateTakeawayScore(restaurants[j], travelTime);

            if (score > bestScore)
            {
                best = j;
                bestScore = score;
            }
        }

        swap(restaurants[i], restaurants[best]);
    }
}

// Display recommendations
void displayTakeawayRecommendations(
    const vector<Restaurant>& restaurants,
    int userLocationId)
{
    cout << "\n========== TAKEAWAY RECOMMENDATIONS ==========\n";

    for (size_t i = 0; i < restaurants.size() && i < 3; i++)
    {
        const Restaurant& restaurant = restaurants[i];

        double distance =
            calculateTakeawayDistance(userLocationId, restaurant);

        double travelTime =
            calculateTakeawayTravelTime(distance);

        double score =
            calculateTakeawayScore(restaurant, travelTime);

        cout << "\n" << i + 1 << ". " << restaurant.name;

        cout << "\nRestaurant ID: " << restaurant.id;

        cout << "\nLocation: " << getLocationById(
            initializeLocations(), restaurant.locationId).name;

        cout << "\nRating: " << restaurant.rating;

        cout << "\nDistance: " << fixed << setprecision(2)
             << distance << " km";

        cout << "\nEstimated Travel Time: "
             << travelTime << " minutes";

        cout << "\nPreparation Time: "
             << restaurant.preparationTime << " minutes";

        cout << "\nTakeaway Score: "
             << score << "/100\n";

        cout << "------------------------------------------\n";
    }
}

// Display selected restaurant menu
void displayTakeawayMenu(
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

// Run complete takeaway module
void runTakeawayModule()
{
    vector<Location> locations = initializeLocations();
    vector<Restaurant> restaurants = initializeRestaurants();
    vector<Cuisine> cuisines = initializeCuisines();
    vector<Dish> dishes = initializeDishes();
    vector<Menu> menus = initializeMenus();

    cout << "\n========== SMARTBITE TAKEAWAY ==========\n";

    int locationId = selectTakeawayLocation(locations);

    if (locationId == -1)
    {
        cout << "Invalid location!\n";
        return;
    }

    int cuisineId = selectTakeawayCuisine(cuisines);

    if (cuisineId == -1)
    {
        cout << "Invalid cuisine!\n";
        return;
    }

    vector<Restaurant> filteredRestaurants =
        findTakeawayRestaurants(
            restaurants, menus, dishes, cuisineId);

    if (filteredRestaurants.empty())
    {
        cout << "\nNo restaurants found for this cuisine.\n";
        return;
    }

    rankTakeawayRestaurants(filteredRestaurants, locationId);

    displayTakeawayRecommendations(
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

    runOrderModule(menus, dishes, selected.id, "Takeaway");
}
