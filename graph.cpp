#include "graph.h"
#include <queue>
#include <limits>

using namespace std;

using namespace std;

Graph::Graph(int numberOfLocations)
{
    adjacencyList.resize(numberOfLocations + 1);
}

void Graph::addEdge(int from, int to, double distance)
{
    adjacencyList[from].push_back({to, distance});
}

const vector<pair<int, double>>& Graph::getNeighbors(int locationId) const
{
    return adjacencyList[locationId];
}

void Graph::buildFromRoads(const vector<Road>& roads)
{
    for (const Road& road : roads)
    {
        addEdge(
            road.fromLocationId,
            road.toLocationId,
            road.distance
        );
    }
}
double Graph::shortestDistance(int start, int destination) const
{
    const double INF = numeric_limits<double>::infinity();

    vector<double> distance(adjacencyList.size(), INF);

    priority_queue<
        pair<double, int>,
        vector<pair<double, int>>,
        greater<pair<double, int>>
    > pq;



    distance[start] = 0;

pq.push({0, start});

while (!pq.empty())
{
    double currentDistance = pq.top().first;
    int currentLocation = pq.top().second;

    pq.pop();

    if (currentDistance > distance[currentLocation])
    {
        continue;
    }

    if (currentLocation == destination)
    {
        return currentDistance;
    }

    for (const auto& neighbor : adjacencyList[currentLocation])
{
    int nextLocation = neighbor.first;
    double roadDistance = neighbor.second;

    double newDistance = currentDistance + roadDistance;

    if (newDistance < distance[nextLocation])
    {
        distance[nextLocation] = newDistance;

        pq.push({newDistance, nextLocation});
    }
}
}
}
