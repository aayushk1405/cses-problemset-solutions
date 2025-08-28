#include<bits/stdc++.h>
using namespace std;

int main(){
  const int MOD=1e9+7;
  int n,x;
  cin>>n>>x;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<int> dp(x+1,-1);
  dp[0]=1;
  for(int i=1;i<=x;i++){
    for(int j=0;j<n;j++){
      if(i-arr[j]>=0 && dp[i]==-1){
        dp[i]=(dp[i]+dp[i-arr[j]])%MOD;
      }
    }
  }
  cout << dp[x] << endl;
  return 0;
}

