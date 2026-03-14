#include<bits/stdc++.h>

using namespace std;

#define int long long int
int32_t main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector < pair < int, int >> vp;
        int s, e;
        for (int i = 0; i < n; i++) {
            cin >> s >> e;
            vp.push_back({
                s,
                1
            });
            vp.push_back({
                e + 1,
                -1
            });
        }
        sort(begin(vp), end(vp));
        
        int c = 0, flag = 1;
        for (auto[_, type]: vp) {
            c += type;
            if (c > 2) {
                flag = 0;
                break;
            }
        }
        
        cout << (flag ? "Yes\n" : "No\n");
    }
}