#include<bits/stdc++.h>
using namespace std;
 
void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){ 
    int n=grid.size();
    int m=grid[0].size();
    vis[row][col]=1;
    queue<pair<int,int>> q;
    q.push({row,col});
    vector<int> delrow={-1,0,+1,0};
    vector<int> delcolumn={0,+1,0,-1};
    while(!q.empty()){
        //very very important method for traversing through all the neighbours of a node in a grid
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcolumn[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='.'){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
}
 
int numProvince(vector<vector<char>> grid){
    int n=grid.size();
    int m=grid[0].size();
    int count=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!vis[row][col] && grid[row][col]=='.'){
                count++;
                bfs(row,col,vis,grid);
            }
        }
    }
    return count;
}
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout << numProvince(grid) << endl;
    return 0;
}