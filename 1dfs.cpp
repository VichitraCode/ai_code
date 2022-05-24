#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 7;

void dfs(int node,int goal,vector<int>v[], vector <bool> &vis, vector <int> &path)
{
    path.push_back(node);
	vis[node] = true;
	if(node==goal)
    {
        for(auto i:path)
            cout<<i<<" ";
        return;
    }
    for(int i=0;i<v[node].size();i++)
    {
		if(!vis[v[node][i]])
		{
			dfs(v[node][i], goal,v,vis, path);
		}
	}
	path.pop_back();
}


int main(){
	cout << "Enter Number Of Nodes and Edges" << "\n";
	int n, m;
	cin >> n >> m;
	cout << "Enter the edges - (u - v)" << "\n";
	vector<int>v[n];
	for(int i = 0; i < m; ++i)
    {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cout << "Enter Staring Node And Goal Node" << "\n";
	int start, goal;
	cin >> start >> goal;
	vector <bool> vis(n + 1, 0);
	vector <int> path;
	dfs(start, goal,v,vis, path);

    return 0;

}
/*
7 6
1 2
1 3
2 4
2 6
6 7
6 8
1 7
*/

