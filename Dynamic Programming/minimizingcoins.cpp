#include<bits/stdc++.h>
using namespace std;

int main(){
  const int MOD=1e9;
  int n,x;
  cin>>n>>x;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<int> dp(x+1,MOD);
  dp[0]=0;
  for(int i=1;i<=x;i++){
    for(int j=0;j<n;j++){
      if(i-arr[j]>=0){
        dp[i]=min(dp[i],1+dp[i-arr[j]]);
      }
    }
  }
  if(dp[x]==MOD){
    cout << -1 << endl;
  }else{
    cout << dp[x] << endl;
  }
  return 0;
}
