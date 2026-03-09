#include<bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n;
    cin >> n;
    vector < int > v(n + 1), pre(n + 1, 0);
    string s;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] ^ v[i];
    }
    cin >> s;
    s = '$' + s;

    int x[2];
    x[0] = x[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') x[1] ^= v[i];
        else x[0] ^= v[i];

    }

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            int val = pre[r] ^ pre[l - 1];
            x[0] ^= val;
            x[1] ^= val;
        }
        else {
            int g;
            cin >> g;
            cout << x[g] << " ";
        }
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