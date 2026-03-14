#include<bits/stdc++.h>

using namespace std;

#define int long long int
const int mod = 1e9 + 7;
int32_t main() {
    int t = 1;
    //cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        
        int res = 1, c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                c++;
            } else if (s[i] == 'b') {
                res *= (c + 1);
                res = res % mod;
                c = 0;
            }
        }
        if (c != 0) res *= (c + 1);
        res = res % mod;
        
        cout << (res - 1 + mod) % mod;
    }
}