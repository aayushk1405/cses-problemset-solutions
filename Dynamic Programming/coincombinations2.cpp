#include<bits/stdc++.h>
using namespace std;
 
int main(){
  const int MOD=1e9+7;
  int n,x;
  cin>>n>>x;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<int> dp(x+1,0);
  dp[0]=1;
  for(int j=0;j<n;j++){
    for(int i=arr[j];i<=x;i++){
      if(i-arr[j]>=0){
        dp[i]=(dp[i]+dp[i-arr[j]])%MOD;
      }
    }
  }
  cout << dp[x] << endl;
  return 0;
}
