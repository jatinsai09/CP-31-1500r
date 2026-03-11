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

        int xr = 0;
        for (auto &i: a) {
            cin >> i;
            xr ^= i;
        }

        if (xr == 0) {
            cout << "YES\n";
            continue;
        }

        int c = 0, cur = 0;
        for (auto &i: a) {
            cur ^= i;
            if (cur == xr) {
                cur = 0;
                c++;
            }
        }

        cout << (c > 1 ? "YES\n" : "NO\n");
    }
}