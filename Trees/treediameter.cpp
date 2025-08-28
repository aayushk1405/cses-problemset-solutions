#include<bits/stdc++.h>
using namespace std;
 
vector<int> depth;
 
void dfs(int vertex,int parent,vector<vector<int>>& adj){
  for(auto child: adj[vertex]){
    if(child==parent) continue;
    depth[child]=depth[vertex]+1;
    dfs(child,vertex,adj);
  }
}
int main(){
  int n;
  cin>>n;
  depth.assign(n+1,0);
  vector<vector<int>> adj(n+1);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,0,adj);
  int mx_depth=-1;
  int mx_node;
  for(int i=1;i<=n;i++){
    if(mx_depth<depth[i]){
      mx_depth=depth[i];
      mx_node=i;
    }
    depth[i]=0;
  }
  dfs(mx_node,0,adj);
  mx_depth=-1;
  for(int i=1;i<=n;i++){
    if(mx_depth<depth[i]){
      mx_depth=depth[i];
    }
  }
  cout << mx_depth << endl;
  return 0;
}
