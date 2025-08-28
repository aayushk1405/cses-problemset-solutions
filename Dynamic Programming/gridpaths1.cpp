#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
int main(){
  int n;
  cin>>n;
  vector<vector<char>> grid(n,vector<char>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>grid[i][j];
    }
  }
  if(grid[n-1][n-1]=='*'){
    cout << 0 << endl;
    return 0;
  }
  vector<vector<int>> dp(n,vector<int>(n,0));
  dp[n-1][n-1]=1;
  for(int r=n-1;r>=0;r--){
    for(int c=n-1;c>=0;c--){
      if(grid[r][c]!='*'){
        if(r+1<n && c<n){
          dp[r][c]=(dp[r][c]+dp[r+1][c])%MOD;
        }
        if(r<n && c+1<n){
          dp[r][c]=(dp[r][c]+dp[r][c+1])%MOD;
        }
      }
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}
