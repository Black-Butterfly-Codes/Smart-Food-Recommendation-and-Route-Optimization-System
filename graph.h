
#ifndef GRAPH_H
#define GRAPH_H

#include "data.h"
#include <vector>

using namespace std;

class Graph
{
private:
    vector<vector<pair<int, double>>> adjacencyList;

public:
    Graph(int numberOfLocations);

    void addEdge(int from, int to, double distance);

    void buildFromRoads(const vector<Road>& roads);

    double shortestDistance(int start, int destination) const;

    const vector<pair<int, double>>& getNeighbors(int locationId) const;
};
#endif
