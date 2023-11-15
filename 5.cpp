#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void displayMatrix(const vector<vector<int>>& graph) {
    int V = graph.size();
    cout << "Distance Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int travllingSalesmanProblem(vector<vector<int>>& graph, int s) {
    int V = graph.size();
    vector<int> vertex;
    
    for (int i = 0; i < V; i++) {
        if (i != s) {
            vertex.push_back(i);
        }
    }
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main() {
    int V;
    cout << "Enter the number of cities: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter distances from one city to another (enter -1 for unreachable cities):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                cout << "Distance from City " << i << " to City " << j << ": ";
                cin >> graph[i][j];
            } else {
                graph[i][j] = 0;  // Distance from a city to itself is 0.
            }
        }
    }
    displayMatrix(graph); // Display the distance matrix
    int s;
    cout << "Enter the starting city (0 to " << V - 1 << "): ";
    cin >> s;
    if (s < 0 || s >= V) {
        cout << "Invalid starting city.\n";
        return 1;
    }
    int minPath = travllingSalesmanProblem(graph, s);
    cout << "Minimum path cost: " << minPath << endl;
    return 0;
}

