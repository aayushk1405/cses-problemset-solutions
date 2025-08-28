#include<bits/stdc++.h>
using namespace std;
 
vector<int> subordinate;
 
void dfs(int vertex,int parent,vector<vector<int>>& adj){
    for(auto child: adj[vertex]){
        if(child==parent) continue;
        dfs(child,vertex,adj);
        subordinate[vertex]+=subordinate[child]+1;
    }
}
int main(){
  int n;
  cin>>n;
  subordinate.assign(n+1,0);
  vector<vector<int>> adj(n+1);
  for(int i=2;i<=n;i++){
    int a;
    cin>>a;
    adj[a].push_back(i);
    adj[i].push_back(a);
  }
  dfs(1,0,adj);
  for(int i=1;i<=n;i++){
    cout << subordinate[i] << " ";
  }
  cout << endl;
  return 0;
}