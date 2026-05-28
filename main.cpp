// Implement main program.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void djalgo(vector<vector<pair<int,int>>>& graph, int start) {
    int numVerts = graph.size();

    vector<int> distances(numVerts, INT_MAX);

    distances[start] = 0;  // whatever we were passed, we set distance to 0, cause it's where we start

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

    minHeap.push({0,start});  // push first location onto heap. heap controls where we look next & will always be next smallest distance

    while (!minHeap.empty()) {

        auto [currDistance, currVert] = minHeap.top();  // set current vert to top of heap
        minHeap.pop();

        if (currDistance > distances[currVert]) continue; // if current distance (weight of current vert) is more than the distance already recorded, restart loop

        // visit downstream neighbors of current vert
        for ( auto [weight,v] : graph[currVert] ) {  // go through adjacency list with a pair iterator
            int newDistance = currDistance + weight;  // calc new distance to compare... = current distance recorded plus new incoming weight
            if (newDistance < distances[v]) {   // if new is less than recorded, update record in vector
                distances[v] = newDistance;
                minHeap.push({newDistance,v});  // push new vector onto heap
            }
        }
    }

    for (int i = 0; i < numVerts; ++i) {
            cout << "Distance to " << i << " = " << distances[i] << endl;
    }
}


int main() {

    const int VERTS = 6;

    // pair = (weight, destination)
    vector<vector<pair<int,int>>> graph(VERTS);

    
    graph[0].push_back({4,1});
    graph[0].push_back({9,2});
    graph[0].push_back({2,4});

    graph[1].push_back({1,3});
    graph[1].push_back({2,2});

    graph[2].push_back({7,3});
    graph[2].push_back({4,5});
    
    graph[3].push_back({1,5});

    graph[4].push_back({3,2});
    graph[4].push_back({8,5});

    djalgo(graph,0);
    
    return 0;
}