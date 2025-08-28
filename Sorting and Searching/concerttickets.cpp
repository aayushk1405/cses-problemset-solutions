#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    multiset<int> h;
    vector<int> t(m);
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        h.insert(p);
    }
    for(int i=0;i<m;i++) cin>>t[i];
    vector<int> ans;
    for(int i=0;i<m;i++){
        auto it=h.upper_bound(t[i]);
        if(it==h.begin()){
            ans.push_back(-1);
        }else{
            --it;
            ans.push_back(*it);
            h.erase(it);
        }
    }
    int size=ans.size();
    for(int i=0;i<size;i++){
        cout << ans[i] << endl;
    }
    cout << endl;
    return 0;
}
