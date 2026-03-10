#include<bits/stdc++.h>

using namespace std;

#define int long long int
void solve() {
    int n;
    cin >> n;
    
    int a[n], b[n];
    for (auto & i: a) cin >> i;
    for (auto & i: b) cin >> i;
    
    vector < int > psum(n, 0), f(n + 1), rem(n + 1);
    psum[0] = b[0];
    for (int i = 1; i < n; i++) {
        psum[i] = b[i] + psum[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int val = a[i];
        if (i > 0) val += psum[i - 1];

        int ind = upper_bound(begin(psum), end(psum), val) - begin(psum);
        f[ind]++;
        int r = val;
        if (ind > 0) {
            r -= psum[ind - 1];
        }
        rem[ind] += r;
    }

    for (int i = 1; i < n; i++) {
        f[i] += f[i - 1];
    }
    for (int i = 0; i < n; i++) {
        int ans = (i + 1 - f[i]) * b[i] + rem[i];
        cout << ans << " ";
    }
    cout << "\n";
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}