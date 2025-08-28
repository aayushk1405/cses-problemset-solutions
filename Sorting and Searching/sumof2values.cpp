#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> v=arr;
    sort(v.begin(),v.end());
    int l=0;
    int r=n-1;
    bool res=false;
    int ans1=-1;
    int ans2=-1;
    while(l<r){
        if(v[l]+v[r]==x){
            res=true;
            ans1=l;
            ans2=r;
            break;
        }
        if(v[l]+v[r]>x){
            r--;
        }else{
            l++;
        }
    }
    if(res){
        if(v[ans2]==v[ans1]){
            int count=0;
            for(int i=0;i<n;i++){
                if(arr[i]==v[ans1]){
                    count++;
                    cout << i+1 << endl;
                    if(count==2){
                        break;
                    }
                }
            }
        }else{
            auto find1=find(arr.begin(),arr.end(),v[ans1]);
            auto find2=find(arr.begin(),arr.end(),v[ans2]);
            int index1=find1-arr.begin();
            int index2=find2-arr.begin();
            cout << min(index1,index2)+1 << " " << max(index2,index1)+1 << endl;
        }
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}