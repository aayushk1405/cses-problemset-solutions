#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, vector<int>& lis) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (lis.empty() || arr[i] > lis.back()) {
            lis.push_back(arr[i]);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> lis;
    solve(arr, lis);
    cout << lis.size() << endl;

    return 0;
}
