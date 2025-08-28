#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int maxn=1e6+5;
int dp[maxn];
 
int solve(vector<int>& c,int sum,int x){
    if(sum==x) return 1;
    if(sum>x) return 0;
    if(dp[sum]!=-1) return dp[sum];
    int ans=0;
    for(int i=0;i<c.size();i++){
        ans=(ans+solve(c,sum+c[i],x))%MOD;
    }
    return dp[sum]=ans;
}
 
int main(){
    memset(dp,-1,sizeof(dp));
    int n,x;
    cin>>n>>x;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    cout << solve(c,0,x) << endl;
    return 0;
}
