#include<bits/stdc++.h>

using namespace std;

#define int long long int
void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int v[n], pre[n];
    for (auto & i: v) cin >> i;

    pre[0] = v[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }

    int ans = b * pre[n - 1];
    int prev = b * v[0];
    for (int i = 0; i < n; i++) {
        ans = min(ans, prev + a * v[i] + (pre[n - 1] - pre[i] - ((n - i - 1) * v[i])) * b);
        if (i + 1 < n) {
            prev += (v[i + 1] - v[i]) * b;
        }
    }
    cout << ans << "\n";
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}