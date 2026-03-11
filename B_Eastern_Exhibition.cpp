#include<bits/stdc++.h>

using namespace std;

#define int long long int
void solve() {
    int n;
    cin >> n;
    int x[n], y[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    if (n & 1) cout << 1 << "\n";
    else {
        sort(x, x + n);
        sort(y, y + n); 

        int mid = n / 2;
        int res = (x[mid] - x[mid - 1] + 1) * (y[mid] - y[mid - 1] + 1);
        
        cout << res << "\n";
    }
    return;
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}