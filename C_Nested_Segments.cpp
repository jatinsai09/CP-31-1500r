#include<bits/stdc++.h>

using namespace std;

#define int long long int
void solve() {
    int n;
    cin >> n;
    
    vector < pair < pair < int, int > , int >> vp(n + 1);
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> vp[i].first.first >> vp[i].first.second;
        vp[i].second = i;
    }
    
    sort(begin(vp), end(vp), [](auto& a, auto& b) {
        if (a.first.first != b.first.first) return a.first.first < b.first.first;
        else return a.first.second > b.first.second;
    });
    
    for (int i = 2; i <= n; i++) {
        if (vp[i].first.second <= vp[i - 1].first.second) {
            cout << vp[i].second << " " << vp[i - 1].second << "\n";
            return;
        }
    }
    cout << -1 << " " << -1 << "\n";
}
int32_t main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}