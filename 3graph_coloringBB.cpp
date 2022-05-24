// Program for DSatur Algorithm for graph coloring.
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;
// Function to add edge between two vertices.
void addEdgeBetween(vector<int> graph[], int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}
// For storing information related to vertices.
class vertexInfo
{
public:
    // Saturation degree of the vertex.
    int sat;
    // degree in uncolored graph
    int deg;
    // index of vertex.
    int vertex;
};
struct maxSat
{
    bool operator()(const vertexInfo &lhs,
                    const vertexInfo &rhs) const
    {
        return tie(lhs.sat, lhs.deg, lhs.vertex) > tie(rhs.sat, rhs.deg, rhs.vertex);
    }
};
// Function to print color of each vertex of graph.
void printcolor(vector<int> &color)
{
    for (int i = 0; i < color.size(); i++)
    {
        cout << "The Color of the vertex " << i << " is " << color[i] << endl;
    }
}
// Function for DSatur algo.
int DSatur(vector<int> graph[], int V)
{
    int u, i;
    // Create vector to store status of used colors.
    vector<bool> use(V, false);
    // Create vector to store colors.
    vector<int> color(V), d(V);
    vector<set<int>> adjCols(V);
    set<vertexInfo, maxSat> Q;
    set<vertexInfo, maxSat>::iterator maxPtr;
    for (u = 0; u < V; u++)
    {
        color[u] = -1;
        d[u] = graph[u].size();
        adjCols[u] = set<int>();
        Q.emplace(vertexInfo{0, d[u], u});
    }
    while (!Q.empty())
    {
        maxPtr = Q.begin();
        u = (*maxPtr).vertex;
        Q.erase(maxPtr);
        for (int v : graph[u])
            if (color[v] != -1)
                use[color[v]] = true;
        i = 0;
        while (i != use.size())
        {
            if (use[i] == false)
                break;
            i++;
        }
        for (auto v : graph[u])
            if (color[v] != -1)
                use[color[v]] = false;
        color[u] = i;
        for (auto v : graph[u])
        {
            if (color[v] == -1)
            {
                Q.erase(
                    {int(adjCols[v].size()),
                     d[v], v});
                adjCols[v].insert(i);
                d[v]--;
                Q.emplace(vertexInfo{
                    int(adjCols[v].size()),
                    d[v], v});
            }
        }
    }
    set<int> ans;
    for (int i = 0; i < V; i++)
        ans.insert(color[i]);
    printcolor(color);
    // Return Chromatic number.
    // Print the Chromatic number of graph coloring.
    cout << "The Chromatic number is : ";
    return ans.size();
}
// Function to calculate Chromatic numvber.
int getChromaticNumber()
{
    // Input number of vertices 'V' and edges 'E'.
    int V, E;
    cin >> V >> E;
    // Create graph of ‘V’ vertices from 0 to V - 1.
    vector<int> graph[V];
    for (int i = 0; i < E; i++)
    {
        // Input edge from vertex 'A' to vertex 'B'.
        int a, b;
        cin >> a >> b;
        // Insert edge between the vertices.
        addEdgeBetween(graph, a, b);
    }
    return DSatur(graph, V);
}
int main()
{
    cout << getChromaticNumber();
    return 0;
}

/*
5 7
1 2
0 3
4 1
2 1
4 2
1 3
4 2
*/
