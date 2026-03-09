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
        for (auto & i: a) cin >> i;

        int dp[n + 1];
        dp[n] = 0;
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            int take = INT_MAX;
            if (a[i] + i < n) {
                take = dp[a[i] + i + 1];
            }
            int notTake = 1 + dp[i + 1];
            
            dp[i] = min(take, notTake);
        }

        cout << dp[0] << "\n";
    }
}