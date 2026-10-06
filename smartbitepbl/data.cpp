#include "data.h"

vector<Location> initializeLocations()
{
    vector<Location> locations;

    locations.push_back({1, "Clock Tower"});
    locations.push_back({2, "Rajpur Road"});
    locations.push_back({3, "ISBT"});
    locations.push_back({4, "Prem Nagar"});
    locations.push_back({5, "Sahastradhara"});

    return locations;
}

Location getLocationById(const vector<Location>& locations, int id)
{
    for (const Location& location : locations)
    {
        if (location.id == id)
        {
            return location;
        }
    }

    return {-1, "Unknown"};
}


vector<Restaurant> initializeRestaurants()
{
    vector<Restaurant> restaurants;

    restaurants.push_back({1, "Spice Garden", 2, 4.5, 20});
    restaurants.push_back({2, "Himalayan Bites", 1, 4.3, 15});
    restaurants.push_back({3, "Pizza Hub", 5, 4.6, 25});
    restaurants.push_back({4, "Green Bowl", 4, 4.2, 18});
    restaurants.push_back({5, "Food Junction", 3, 4.4, 22});

    return restaurants;
}

Restaurant getRestaurantById(const vector<Restaurant>& restaurants, int id)
{
    for (const Restaurant& restaurant : restaurants)
    {
        if (restaurant.id == id)
        {
            return restaurant;
        }
    }

    return {-1, "Unknown", -1, 0.0, 0};
}

vector<Cuisine> initializeCuisines()
{
    vector<Cuisine> cuisines;

    cuisines.push_back({1, "Indian"});
    cuisines.push_back({2, "Chinese"});
    cuisines.push_back({3, "Italian"});
    cuisines.push_back({4, "Mexican"});
    cuisines.push_back({5, "South Indian"});
    cuisines.push_back({6, "Fast Food"});

    return cuisines;
}


Cuisine getCuisineById(const vector<Cuisine>& cuisines, int id)
{
    for (const Cuisine& cuisine : cuisines)
    {
        if (cuisine.id == id)
        {
            return cuisine;
        }
    }

    return {-1, "Unknown"};
}


vector<Dish> initializeDishes()
{
    vector<Dish> dishes;

    // Indian
    dishes.push_back({1, "Butter Chicken", 1, 250, false});
    dishes.push_back({2, "Paneer Tikka", 1, 180, true});
    dishes.push_back({3, "Dal Makhani", 1, 160, true});
    dishes.push_back({4, "Biryani", 1, 220, false});

    // Chinese
    dishes.push_back({5, "Hakka Noodles", 2, 150, true});
    dishes.push_back({6, "Fried Rice", 2, 160, true});
    dishes.push_back({7, "Manchurian", 2, 170, true});
    dishes.push_back({8, "Spring Rolls", 2, 140, true});

    // Italian
    dishes.push_back({9, "Margherita Pizza", 3, 220, true});
    dishes.push_back({10, "Pasta Alfredo", 3, 200, true});
    dishes.push_back({11, "Garlic Bread", 3, 120, true});
    dishes.push_back({12, "Lasagna", 3, 250, true});

    // Mexican
    dishes.push_back({13, "Veg Tacos", 4, 160, true});
    dishes.push_back({14, "Burrito", 4, 180, true});
    dishes.push_back({15, "Nachos", 4, 140, true});
    dishes.push_back({16, "Quesadilla", 4, 170, true});

    // South Indian
    dishes.push_back({17, "Masala Dosa", 5, 120, true});
    dishes.push_back({18, "Idli Sambar", 5, 100, true});
    dishes.push_back({19, "Vada", 5, 90, true});
    dishes.push_back({20, "Uttapam", 5, 110, true});

    // Fast Food
    dishes.push_back({21, "Burger", 6, 150, false});
    dishes.push_back({22, "French Fries", 6, 100, true});
    dishes.push_back({23, "Momos", 6, 130, true});
    dishes.push_back({24, "Sandwich", 6, 120, true});

    return dishes;
}


Dish getDishById(const vector<Dish>& dishes, int id)
{
    for (const Dish& dish : dishes)
    {
        if (dish.id == id)
        {
            return dish;
        }
    }

    return {-1, "Unknown", -1, 0.0, false};
}



vector<Menu> initializeMenus()
{
    vector<Menu> menus;

    // Spice Garden
    menus.push_back({1, 1});  // Butter Chicken
    menus.push_back({1, 2});  // Paneer Tikka
    menus.push_back({1, 3});  // Dal Makhani
    menus.push_back({1, 5});  // Hakka Noodles
    menus.push_back({1, 7});  // Manchurian
    menus.push_back({1, 17}); // Masala Dosa

    // Himalayan Bites
    menus.push_back({2, 1});  // Butter Chicken
    menus.push_back({2, 2});  // Paneer Tikka
    menus.push_back({2, 4});  // Biryani
    menus.push_back({2, 6});  // Fried Rice
    menus.push_back({2, 8});  // Spring Rolls

    // Pizza Hub
    menus.push_back({3, 9});  // Margherita Pizza
    menus.push_back({3, 10}); // Pasta Alfredo
    menus.push_back({3, 11}); // Garlic Bread
    menus.push_back({3, 12}); // Lasagna
    menus.push_back({3, 21}); // Burger
    menus.push_back({3, 22}); // French Fries

    // Green Bowl
    menus.push_back({4, 2});  // Paneer Tikka
    menus.push_back({4, 3});  // Dal Makhani
    menus.push_back({4, 6});  // Fried Rice
    menus.push_back({4, 8});  // Spring Rolls
    menus.push_back({4, 13}); // Veg Tacos
    menus.push_back({4, 15}); // Nachos

    // Food Junction
    menus.push_back({5, 17}); // Masala Dosa
    menus.push_back({5, 18}); // Idli Sambar
    menus.push_back({5, 20}); // Uttapam
    menus.push_back({5, 21}); // Burger
    menus.push_back({5, 23}); // Momos
    menus.push_back({5, 24}); // Sandwich

    return menus;
}

vector<Dish> getRestaurantMenu(const vector<Menu>& menus,
                               const vector<Dish>& dishes,
                               int restaurantId)
{
    vector<Dish> restaurantMenu;

    for (const Menu& menu : menus)
    {
        if (menu.restaurantId == restaurantId)
        {
            Dish dish = getDishById(dishes, menu.dishId);

            if (dish.id != -1)
            {
                restaurantMenu.push_back(dish);
            }
        }
    }

    return restaurantMenu;
}


vector<Road> initializeRoads()
{
    vector<Road> roads;

    roads.push_back({1, 2, 3}); // Clock Tower → Rajpur Road
    roads.push_back({1, 3, 5}); // Clock Tower → ISBT
    roads.push_back({2, 5, 7}); // Rajpur Road → Sahastradhara
    roads.push_back({3, 4, 6}); // ISBT → Prem Nagar
    roads.push_back({4, 1, 4}); // Prem Nagar → Clock Tower

    return roads;
}

void addRoad(vector<Road>& roads,
             int fromLocationId,
             int toLocationId,
             double distance)
{
    roads.push_back({fromLocationId, toLocationId, distance});
}

const vector<Road>& getRoads(const vector<Road>& roads)
{
    return roads;
}


vector<Restaurant> findRestaurantsByCuisine(
    const vector<Restaurant>& restaurants,
    const vector<Menu>& menus,
    const vector<Dish>& dishes,
    int cuisineId)
{
    vector<Restaurant> result;

    for (const Restaurant& restaurant : restaurants)
    {
        for (const Menu& menu : menus)
        {
            if (menu.restaurantId == restaurant.id)
            {
                Dish dish = getDishById(dishes, menu.dishId);

                if (dish.cuisineId == cuisineId)
                {
                    result.push_back(restaurant);
                    break;
                }
            }
        }
    }

    return result;
}

vector<Restaurant> findRestaurantsByRating(
    const vector<Restaurant>& restaurants,
    double minimumRating)
{
    vector<Restaurant> result;

    for (const Restaurant& restaurant : restaurants)
    {
        if (restaurant.rating >= minimumRating)
        {
            result.push_back(restaurant);
        }
    }

    return result;
}


vector<Restaurant> findRestaurantsByLocation(
    const vector<Restaurant>& restaurants,
    int locationId)
{
    vector<Restaurant> result;

    for (const Restaurant& restaurant : restaurants)
    {
        if (restaurant.locationId == locationId)
        {
            result.push_back(restaurant);
        }
    }

    return result;
}

