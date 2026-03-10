#include<bits/stdc++.h>

using namespace std;

#define int long long int

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int p = 0, m = 0;
    for (auto& ch: s) {
        if (ch == '+') p++;
        else m++;
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int dif = p - m;
        
        if (dif == 0) {
            cout << "YES\n";
            continue;
        }
        
        if (x == y) {
            if (dif == 0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        
        int k = (dif * y) / (y - x);
        int rem = (dif * y) % (y - x);
        
        if (k <= p && k >= -m && rem == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
int32_t main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}