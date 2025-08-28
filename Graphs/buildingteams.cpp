#include<bits/stdc++.h>
using namespace std;
 
bool bfs(int node,vector<vector<int>>& adj,vector<int>& color,int vis[]){
    vis[node]=1;
    color[node]=1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto it: adj[front]){
            if(!vis[it]){
                vis[it]=1;
                color[it]=3-color[front];
                q.push(it);
            }else{
                if(color[it]==color[front]) return false;
            }
        }
    }
    return true;
}
bool check(int n,vector<vector<int>>& adj,vector<int>& color){
    int vis[n+1]={0};
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(!bfs(i,adj,color,vis)) return false;
        }
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(n+1);
    if(!check(n,adj,color)){
        cout << "IMPOSSIBLE" << endl;
    }else{
        for(int i=1;i<=n;i++){
            cout << color[i] << " ";
        }
        cout << endl;
    }
}
