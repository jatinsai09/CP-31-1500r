#include<bits/stdc++.h>

using namespace std;

#define int long long int
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int r = k / 2;
    for (int i = 0; i < k; i++) {
        if (s[i] != '?') {
            continue;
        }
    
        for (int j = i + k; j < n; j += k) {
            if (s[j] != '?') {
                s[i] = s[j];
                break;
            }
        }
        
    }

    for (int i = 0; i < k; i++) {
        if (s[i] == '?') {
            continue;
        }

        for (int j = i + k; j < n; j += k) {
            if (s[j] == '?') {
                s[j] = s[i];
            }
            else if (s[i] != s[j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    
    int c1 = 0, c2 = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '?') {
            continue;
        }
        (s[i] == '0' ? c2++ : c1++);
    }

    cout << (c1 <= r && c2 <= r ? "YES\n" : "NO\n");
    return;

}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}