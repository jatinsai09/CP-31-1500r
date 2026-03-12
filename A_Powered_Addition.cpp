#include<bits/stdc++.h>

using namespace std;

#define int long long int
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int a[n], mx = INT_MIN, val = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
            val = max(val, mx - a[i]);
        }

        int res = 0;
        while ((1LL << res) - 1 < val) {
            res++;
        }
        cout << res << "\n";
    }
}