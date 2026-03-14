#include<bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n, q;
    cin >> n >> q;
    
    int a[n];
    vector < int > rsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int l, r;
    while (q--) {
        cin >> l >> r;
        l--;
        r--;
        rsum[l]++;
        rsum[r + 1]--;
    }
    
    for (int i = 1; i < n; i++) {
        rsum[i] += rsum[i - 1];
    }
    sort(a, a + n, greater < int > ());
    sort(rbegin(rsum), rend(rsum));
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += (a[i] * rsum[i]);
    }
    
    cout << res;
}
int32_t main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}