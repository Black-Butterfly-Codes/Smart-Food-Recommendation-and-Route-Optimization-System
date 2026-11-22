#ifndef DINING_H
#define DINING_H

#include "data.h"
#include "graph.h"

double calculateDiningDistance(const Graph& graph,int startLocationId,int restaurantLocationId);

double calculateDiningScore(double distance,double rating);
vector<Restaurant> rankDiningRestaurants(const vector<Restaurant>& restaurants,const Graph& graph,int startLocationId);

int selectDiningLocation();

int selectDiningCuisine();

void displayDiningRestaurants(const vector<Restaurant>& restaurants,const vector<Location>& locations);

int selectDiningRestaurant(const vector<Restaurant>& restaurants);

void showDiningRestaurantDetails(const Restaurant& restaurant,const vector<Location>& locations);

void displayDiningMenu(const vector<Menu>& menus,const vector<Dish>& dishes,int restaurantId);


void runDiningModule();


#endif
