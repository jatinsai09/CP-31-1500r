#include<bits/stdc++.h>

using namespace std;

#define int long long int
int32_t main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        int n, g = 0, ones = 0;
        cin >> n;
        
        int a[n];
        for (auto & i: a) {
            cin >> i;
            g = __gcd(g, i);
            ones += (i == 1 ? 1 : 0);
        }
        
        if (g > 1) {
            cout << -1 << endl;
            continue;
        }
        if (ones > 0) {
            cout << n - ones;
            continue;
        }

        int minlen = n;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            for (int j = i + 1; j < n; j++) {
                x = __gcd(a[j], x);
                if (x == 1) {
                    minlen = min(j - i + 1, minlen);
                    break;
                }
            }
        }
        
        cout << minlen - 1 + n - 1;
    }
}