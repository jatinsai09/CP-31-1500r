#include<bits/stdc++.h>

using namespace std;

#define int long long int
signed main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        
        int a[n], b[n];
        for (auto & i: a) cin >> i;
        for (auto & i: b) cin >> i;

        priority_queue < int > pq;
        for (int i = 0; i < n; i++) {
            pq.push(abs(a[i] - b[i]));
        }
        
        int k = k1 + k2;
        while (k > 0) {
            int d = pq.top();
            pq.pop();
            
            if (!d) {
                break;
            }
            
            pq.push(d - 1);
            k--;
        }

        int res = 0;
        while (pq.size() && pq.top() != 0) {
            res += pow(pq.top(), 2);
            pq.pop();
        }
        
        cout << res + (k & 1);
    }
}