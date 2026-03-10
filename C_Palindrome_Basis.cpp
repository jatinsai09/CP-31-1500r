#include<bits/stdc++.h>

using namespace std;
//#define int long long int
const int MOD = 1e9 + 7;
const int N = 4e4 + 9;
vector < int > pal, dp(N, 0);

int main() {

    for (int i = 1; i < N; i++) {
        string s1 = to_string(i);
        string s2 = s1;
        reverse(begin(s2), end(s2));
        if (s1 == s2) {
            pal.push_back(i);
        }
    }

    dp[0] = 1;
    for (auto& j: pal) {
        for (int i = j; i < N; i++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}