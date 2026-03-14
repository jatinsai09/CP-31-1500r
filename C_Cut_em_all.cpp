#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define MAX LLONG_MAX
#define MIN LLONG_MIN
const int MOD = 1e9 + 7;

ll add(ll a, ll b, ll m = MOD) {
    return ((a % m) + (b % m) + m) % m;
};
ll sub(ll a, ll b, ll m = MOD) {
    return ((a % m) - (b % m) + m) % m;
};
ll mul(ll a, ll b, ll m = MOD) {
    return ((a % m) * (b % m)) % m;
};
ll modExp(ll a, ll e, ll m = MOD) {
    a % m;
    ll r = 1;
    while (e) {
        if (e & 1) {
            r = mul(r, a, m);
        }
        a = mul(a, a, m);
        e >>= 1;
    }

    return r;
}
ll inv(ll a, ll m = MOD) {
    return modExp(a, m - 2, m);
};

class DSU {
    public: vector < int > parent,
    size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);

        if (px == py) {
            return false;
        }

        if (size[py] < size[px]) {
            parent[py] = px;
            size[px] += size[py];
        }
        else {
            parent[px] = py;
            size[py] += size[px];
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;

        vector < vector < int >> adj(n + 1);
        ll u, v;
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (n & 1) {
            cout << "-1\n";
            continue;
        }

        ll res = 0;
        vector < int > f(n + 1);

        auto dfs = [ & ](auto && fn, int x, int p) -> void {
            f[x] = 1;
            for (auto nbr: adj[x]) {
                if (nbr == p) {
                    continue;
                }
                
                fn(fn, nbr, x);

                if (f[nbr] % 2 == 0) {
                    res++;
                    f[nbr] = 0;
                }

                f[x] += f[nbr];
            }
        };

        dfs(dfs, 1, 0);

        cout << res << "\n";
    }
    // your code goes here
}