#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  int maxsum=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    maxsum+=arr[i];
  }
  vector<bool> dp(maxsum+1,false);
  dp[0]=true;
  for(int j=0;j<n;j++){
    for(int i=maxsum;i>=arr[j];i--){
      if(dp[i-arr[j]]){
        dp[i]=true;
      }
    }
  }
  int count=0;
  set<int> s;
  for(int i=1;i<=maxsum;i++){
    if(dp[i]){
      count++;
      s.insert(i);
    }
  }
  cout << count << endl;
  auto it=s.begin();
  while(it!=s.end()){
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}