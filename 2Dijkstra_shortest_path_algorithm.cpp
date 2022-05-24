#include <bits/stdc++.h>
using namespace std;

int V;

int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
        if (sptSet[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;
    return min_index;
}

void printPath(int parent[], int j){
    // Base Case : If j is source
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    cout << j << " ";
}

void printSolution(int dist[], int n, int parent[]){
    int src = 0;
    cout << "Vertex\t Distance\tPath";
    for (int i = 1; i < V; i++) {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i],
            src);
        printPath(parent, i);
    }
}

void dijkstra(vector <vector<int>> &graph, int src){

    int dist[V];
    bool sptSet[V] = { false };

    // Parent array to store shortest path tree
    int parent[V] = { -1 };

    // Initialize all distances as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v]
                && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    // print the constructed distance array
    printSolution(dist, V, parent);
}

int main()
{
    cout << "Enter the NUmber of vertices : " << " ";
    cin >> V;
    vector <vector<int>> graph(V, vector <int> (V, 0));
    cout << "Enter Adjacency Matrix" << "\n";
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j)
            cin >> graph[i][j];
    }
    dijkstra(graph, 0);
    return 0;
}
/*
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 0 10 0 2 0 0
0 0 0 14 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/
