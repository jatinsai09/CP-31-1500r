#include <bits/stdc++.h>

using namespace std;

#define int long long int 

const int N = 4e4 + 9;
int n, m, k;
int a[N], b[N];

int ans(int x, int y) {
    int c = 0, rc = 0, cc = 0;
    for (int i = 0; i < n; i++) {
        a[i] ? (c++) : (c = 0);
        if (c >= x) rc++;
    }

    c = 0;
    for (int i = 0; i < m; i++) {
        b[i] ? (c++) : (c = 0);
        if (c >= y) cc++;
    }
    return rc * cc;
}

void solve() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int res = 0;
    for (int i = 1; i <= sqrt(k); i++) {
        if (k % i == 0) {
            res += (i * i == k) ? ans(i, i) : (ans(i, k / i) + ans(k / i, i));
        }
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