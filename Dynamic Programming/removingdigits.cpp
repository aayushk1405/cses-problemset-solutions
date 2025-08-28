#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int solve(int x){
  if(x==0) return 0;
  vector<int> ans;
  int p=x;
  while(p!=0){
    int rem=p%10;
    ans.push_back(rem);
    p=p/10;
  }
  sort(ans.begin(),ans.end());
  return 1+solve(x-ans[ans.size()-1]);
}
int main(){
  int n;
  cin>>n;
  cout << solve(n) << endl;
  return 0;
}