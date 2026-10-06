#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

using namespace std;

struct Location
{
    int id;
    string name;
};

struct Restaurant
{
    int id;
    string name;
    int locationId;
    double rating;
    int preparationTime;
};
struct Cuisine
{
    int id;
    string name;
};
struct Dish
{
    int id;
    string name;
    int cuisineId;
    double price;
    bool vegetarian;
};
struct Menu
{
    int restaurantId;
    int dishId;
};
struct Road
{
    int fromLocationId;
    int toLocationId;
    double distance;
};
vector<Location> initializeLocations();

Location getLocationById(const vector<Location>& locations, int id);

vector<Restaurant> initializeRestaurants();

Restaurant getRestaurantById(const vector<Restaurant>& restaurants, int id);


vector<Cuisine> initializeCuisines();

Cuisine getCuisineById(const vector<Cuisine>& cuisines, int id);


vector<Dish> initializeDishes();

Dish getDishById(const vector<Dish>& dishes, int id);


vector<Menu> initializeMenus();

vector<Dish> getRestaurantMenu(const vector<Menu>& menus,const vector<Dish>& dishes,int restaurantId);


vector<Road> initializeRoads();

void addRoad(vector<Road>& roads,int fromLocationId,int toLocationId,double distance);

const vector<Road>& getRoads(const vector<Road>& roads);


vector<Restaurant> findRestaurantsByCuisine(const vector<Restaurant>& restaurants,const vector<Menu>& menus,const vector<Dish>& dishes,int cuisineId);

vector<Restaurant> findRestaurantsByRating(const vector<Restaurant>& restaurants,double minimumRating);

vector<Restaurant> findRestaurantsByLocation(const vector<Restaurant>& restaurants,int locationId);


#endif
