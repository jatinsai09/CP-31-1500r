#include<bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int p = 0, m = 0;
    int ans = 0;

    for (int i = 0; i < k / 2; i++) {
        int f[26] = {
            0
        };
        for (int sg = 0; sg + k - 1 < n; sg += k) {
            int i1 = sg + i;
            int i2 = sg + (k - i - 1);

            f[s[i1] - 'a']++;
            f[s[i2] - 'a']++;
        }

        int req = 2 * (n / k);
        int mx = * max_element(f, f + 26);
        ans += (req - mx);
    }

    if (k & 1) {
        int f[26] = {
            0
        };
        for (int i = k / 2; i < n; i += k) {
            f[s[i] - 'a']++;
        }
        int mx = * max_element(f, f + 26);
        int req = (n / k);
        ans += (req - mx);
    }
    
    cout << ans << endl;
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}