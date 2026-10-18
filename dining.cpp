#include "dining.h"
#include <iostream>

using namespace std;

int selectDiningLocation()
{
    int choice;

    cout << "\n===== SELECT LOCATION =====" << endl;

    cout << "1. Clock Tower" << endl;
    cout << "2. Rajpur Road" << endl;
    cout << "3. ISBT" << endl;
    cout << "4. Prem Nagar" << endl;
    cout << "5. Sahastradhara" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= 5)
    {
        return choice;
    }

    cout << "Invalid location." << endl;
    return 0;
}

vector<Restaurant> findDiningRestaurants(const vector<Restaurant>& restaurants,const vector<Menu>& menus,const vector<Dish>& dishes,int locationId,int cuisineId)
{
    vector<Restaurant> result;

    for (const Restaurant& restaurant : restaurants)
    {
        vector<Restaurant> cuisineRestaurants =
            findRestaurantsByCuisine(
                vector<Restaurant>{restaurant},
                menus,
                dishes,
                cuisineId);

        if (!cuisineRestaurants.empty())
        {
            result.push_back(restaurant);
        }
    }

    return result;
}


int selectDiningCuisine()
{
    int choice;

    cout << "\n===== SELECT CUISINE =====" << endl;

    cout << "1. Indian" << endl;
    cout << "2. Chinese" << endl;
    cout << "3. Italian" << endl;
    cout << "4. Mexican" << endl;
    cout << "5. South Indian" << endl;
    cout << "6. Fast Food" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= 6)
    {
        return choice;
    }

    cout << "Invalid cuisine." << endl;
    return 0;
}




void displayDiningRestaurants(const vector<Restaurant>& restaurants,const vector<Location>& locations)
{
    cout << "\n===== AVAILABLE RESTAURANTS =====" << endl;

    if (restaurants.empty())
    {
        cout << "No restaurants found." << endl;
        return;
    }

    for (const Restaurant& restaurant : restaurants)
    {
        Location location =
            getLocationById(locations, restaurant.locationId);

        cout << "\nRestaurant: " << restaurant.name << endl;
        cout << "Location: " << location.name << endl;
        cout << "Rating: " << restaurant.rating << endl;
        cout << "Preparation Time: "
             << restaurant.preparationTime << " minutes" << endl;
    }
}




int selectDiningRestaurant(const vector<Restaurant>& restaurants)
{
    int choice;

    if (restaurants.empty())
    {
        return 0;
    }

    cout << "\n===== SELECT RESTAURANT =====" << endl;

    for (int i = 0; i < restaurants.size(); i++)
    {
        cout << i + 1 << ". "
             << restaurants[i].name << endl;
    }

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= restaurants.size())
    {
        return restaurants[choice - 1].id;
    }

    cout << "Invalid restaurant." << endl;
    return 0;
}




void showDiningRestaurantDetails(const Restaurant& restaurant,const vector<Location>& locations)
{
    Location location =
        getLocationById(locations, restaurant.locationId);

    cout << "\n===== RESTAURANT DETAILS =====" << endl;

    cout << "Restaurant: "
         << restaurant.name << endl;

    cout << "Location: "
         << location.name << endl;

    cout << "Rating: "
         << restaurant.rating << endl;

    cout << "Preparation Time: "
         << restaurant.preparationTime
         << " minutes" << endl;
}




void displayDiningMenu(
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int restaurantId)
{
    vector<Dish> restaurantMenu =
        getRestaurantMenu(menus, dishes, restaurantId);

    cout << "\n===== RESTAURANT MENU =====" << endl;

    if (restaurantMenu.empty())
    {
        cout << "No menu available." << endl;
        return;
    }

    for (const Dish& dish : restaurantMenu)
    {
        cout << dish.name
             << " - Rs. "
             << dish.price;

        if (dish.vegetarian)
        {
            cout << " (Veg)";
        }
        else
        {
            cout << " (Non-Veg)";
        }

        cout << endl;
    }
}

double calculateDiningDistance(const Graph& graph,int startLocationId,int restaurantLocationId)
{
    return graph.shortestDistance(startLocationId,restaurantLocationId);
}

double calculateDiningScore(double distance,double rating)
{
    double distanceScore = 100.0 / (1.0 + distance);

    double ratingScore = (rating / 5.0) * 100.0;

    double finalScore =
        (distanceScore * 0.60) +
        (ratingScore * 0.40);

    return finalScore;
}

vector<Restaurant> rankDiningRestaurants(
    const vector<Restaurant>& restaurants,
    const Graph& graph,
    int startLocationId)
{
    vector<Restaurant> rankedRestaurants = restaurants;

    for (int i = 0; i < rankedRestaurants.size() - 1; i++)
    {
        int bestIndex = i;

        double bestDistance = calculateDiningDistance(
            graph,
            startLocationId,
            rankedRestaurants[bestIndex].locationId);

        double bestScore = calculateDiningScore(
            bestDistance,
            rankedRestaurants[bestIndex].rating);

        for (int j = i + 1; j < rankedRestaurants.size(); j++)
        {
            double distance = calculateDiningDistance(
                graph,
                startLocationId,
                rankedRestaurants[j].locationId);

            double score = calculateDiningScore(
                distance,
                rankedRestaurants[j].rating);

            if (score > bestScore)
            {
                bestIndex = j;
                bestScore = score;
            }
        }

        if (bestIndex != i)
        {
            Restaurant temp = rankedRestaurants[i];
            rankedRestaurants[i] = rankedRestaurants[bestIndex];
            rankedRestaurants[bestIndex] = temp;
        }
    }

    return rankedRestaurants;
}

void displayDiningRecommendations(
    const vector<Restaurant>& restaurants,
    const vector<Location>& locations,
    const Graph& graph,
    int startLocationId)
{
    cout << "\n===== DINING RECOMMENDATIONS =====" << endl;

    if (restaurants.empty())
    {
        cout << "No restaurants found." << endl;
        return;
    }

    int limit = restaurants.size();

    if (limit > 3)
    {
        limit = 3;
    }

    for (int i = 0; i < limit; i++)
    {
        double distance = calculateDiningDistance(
            graph,
            startLocationId,
            restaurants[i].locationId);

        double score = calculateDiningScore(
            distance,
            restaurants[i].rating);

        Location location =
            getLocationById(locations, restaurants[i].locationId);

        cout << "\n";

        if (i == 0)
            cout << "1. BEST CHOICE" << endl;
        else if (i == 1)
            cout << "2. SECOND BEST" << endl;
        else
            cout << "3. THIRD BEST" << endl;

        cout << "Restaurant: "
             << restaurants[i].name << endl;

        cout << "Location: "
             << location.name << endl;

        cout << "Rating: "
             << restaurants[i].rating << endl;

        cout << "Distance: "
             << distance << " km" << endl;

        cout << "Dining Score: "
             << score << endl;
    }
}

void runDiningModule()
{
    vector<Location> locations =
        initializeLocations();

    vector<Restaurant> restaurants =
        initializeRestaurants();

    vector<Cuisine> cuisines =
        initializeCuisines();

    vector<Dish> dishes =
        initializeDishes();

    vector<Menu> menus =
        initializeMenus();

    vector<Road> roads =
        initializeRoads();

    Graph graph(5);

    graph.buildFromRoads(roads);

    cout << "\n===== DINING MODULE ====="
         << endl;

    int locationId =
        selectDiningLocation();

    if (locationId == 0)
    {
        return;
    }

    int cuisineId =
        selectDiningCuisine();

    if (cuisineId == 0)
    {
        return;
    }

    vector<Restaurant> matchingRestaurants =
        findDiningRestaurants(
            restaurants,
            menus,
            dishes,
            locationId,
            cuisineId);

    vector<Restaurant> rankedRestaurants =
        rankDiningRestaurants(
            matchingRestaurants,
            graph,
            locationId);

    displayDiningRecommendations(
        rankedRestaurants,
        locations,
        graph,
        locationId);

    int restaurantId =
        selectDiningRestaurant(
            rankedRestaurants);

    if (restaurantId == 0)
    {
        return;
    }

    Restaurant selectedRestaurant =
        getRestaurantById(
            restaurants,
            restaurantId);

    showDiningRestaurantDetails(
        selectedRestaurant,
        locations);

    displayDiningMenu(
        menus,
        dishes,
        restaurantId);
}
