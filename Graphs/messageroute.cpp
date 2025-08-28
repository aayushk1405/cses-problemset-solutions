#include <bits/stdc++.h>
using namespace std;
//function for finding shortest path between 2 points in an undirected unweighted graph(ONLY BFS)
void bfs(int start, int end, vector<vector<int>>& adj, vector<int>& path, bool& res) {
    int n = adj.size() - 1;
    vector<int> vis(n + 1, 0);
    vector<int> parent(n + 1, -1);
 
    queue<int> q;
    vis[start] = 1;
    q.push(start);
 
    while (!q.empty()) {
        int node = q.front();
        q.pop();
 
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                parent[it] = node;
                q.push(it);
 
                if (it == end) break;
            }
        }
    }
    if (!vis[end]) {
        res = false;
        return;
    }
    // Reconstruct path from end → start using parent[]
    for (int cur = end; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
}
 
void shortestpath(int n, vector<vector<int>>& adj, vector<int>& path, bool& res) {
    bfs(1, n, adj, path, res);
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    vector<int> path;
    bool res = true;
    shortestpath(n, adj, path, res);
 
    if (!res) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << path.size() << endl;
        for (int x : path) cout << x << " ";
        cout << endl;
    }
 
    return 0;
}
