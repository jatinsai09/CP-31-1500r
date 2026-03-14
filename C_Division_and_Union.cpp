#include<bits/stdc++.h>

using namespace std;

#define int long long int
pair < pair < int, int > , int > sg[111111];
int n, res[111111];

void answer() {
    for (int i = 1; i <= n; i++) {
        if (res[i]) cout << 1 << " ";
        else cout << 2 << " ";
    }
    cout << "\n";
    return;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sg[i].first.first >> sg[i].first.second;
        sg[i].second = i;
        res[i] = 0;
    }
    sort(sg + 1, sg + n + 1);

    int rmx = 0;
    for (int i = 1; i <= n; i++) {
        if (i != 1 && sg[i].first.first > rmx) {
            answer();
            return;
        }
        res[sg[i].second] = 1;
        rmx = max(rmx, sg[i].first.second);
    }
    cout << -1 << endl;
    return;
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}