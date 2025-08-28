#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
int main(){
  int n,x;
  cin>>n>>x;
  vector<int> price(n);
  vector<int> pages(n);
  for(int i=0;i<n;i++) cin>>price[i];
  for(int i=0;i<n;i++) cin>>pages[i];
  vector<vector<int>> dp(n+1,vector<int>(x+1,0));
  for(int i=1;i<=n;i++){
    for(int cost=0;cost<=x;cost++){
      dp[i][cost]=dp[i-1][cost];
      if(cost>=price[i-1]){
        dp[i][cost]=max(dp[i-1][cost],(dp[i-1][cost-price[i-1]]) + pages[i-1]);
      }
    }
  }
  cout << dp[n][x] << endl;
  return 0;
}