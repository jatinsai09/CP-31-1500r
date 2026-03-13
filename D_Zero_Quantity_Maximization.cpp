#include <bits/stdc++.h>

using namespace std;
#define int long long int
int32_t main() {
    int n;
    cin >> n;
    
    vector < int > a(n), b(n);
    for (auto & i: a) {
        cin >> i;
    }
    for (auto & i: b) {
        cin >> i;
    }
    
    int mx = 0, c = 0;
    map < pair < int, int > , int > mp;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            c += !b[i];
            continue;
        }
        
        int g = __gcd(a[i], b[i]);
        ++mp[{
            a[i] / g,
            b[i] / g
        }];
    }

    for (auto& i: mp) {
        mx = max(mx, i.second);
    }
    cout << mx + c;
    // your code goes here
}