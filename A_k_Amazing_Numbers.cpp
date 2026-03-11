#include<bits/stdc++.h>

using namespace std;

#define int long long int
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        vector < vector < int >> v(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            v[a[i] - 1].push_back(i);
        }

        vector < int > dp(n + 2, n + 1);
        int mx, start;

        for (int i = 0; i < n; i++) {
            mx = 0, start = -1;

            for (auto& j: v[i]) {
                mx = max(j - start, mx);
                start = j;
            }
            mx = max(mx, n - start);

            dp[mx] = min(i, dp[mx]);
        }

        int mn = n + 1;
        for (int i = 1; i <= n; i++) {
            mn = min(dp[i], mn);

            cout << (mn > n ? -1 : mn + 1) << " ";
        }
        cout << "\n";
    }
}