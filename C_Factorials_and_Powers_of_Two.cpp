#include<bits/stdc++.h>

using namespace std;

#define int long long int
int cnt(int n) {
    int res = 0;
    while (n) {
        if (n % 2) res++;
        n /= 2;
    }
    return res;
}

int32_t main() {
    int t = 1;
    cin >> t;
    int fact[14];
    fact[0] = 1;
    for (int i = 1; i < 14; i++) {
        fact[i] = (i + 1) * fact[i - 1];
    }
    while (t--) {
        int n;
        cin >> n;

        int res = INT_MAX;
        for (int i = 0; i < (1 << 14LL); i++) {
            int sum = 0, tmp = 0;
            for (int j = 0; j < 14; j++) {
                if (i & (1 << j)) {
                    sum += fact[j];
                    tmp++;
                }
            }
            if (sum > n) break;
    
            tmp += cnt(n - sum);
            res = min(res, tmp);
        }
        
        cout << res << "\n";
    }
}