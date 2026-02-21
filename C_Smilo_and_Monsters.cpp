#include<bits/stdc++.h>

using namespace std;

#define int long long int
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], sum = 0;
        for (auto & i: a) {
            cin >> i;
            sum += i;
        }
        sort(a, a + n);
        
        int res = 0;
        res += (sum & 1);
        sum /= 2;
        res += sum;
        
        int j = n - 1;
        while (sum > 0) {
            sum -= a[j];
            j--;
            res++;
        }
        cout << res << endl;
    }
}