#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file

#include <ext/pb_ds/tree_policy.hpp>

#include <functional> // for less

using namespace __gnu_pbds;
using namespace std;

// Declaring ordered_set 
typedef tree < int, null_type, less < int > , rb_tree_tag,
    tree_order_statistics_node_update >
    oset;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        oset s;
        vector < pair < int, int >> vp(n);
        for (auto & [a, b]: vp) {
            cin >> a >> b;
        }
        sort(vp.begin(), vp.end());

        for (auto & [a, b]: vp) {
            s.insert(b); // Inserting after sorting to maintain order
        }

        long long int c = 0;
        for (auto & [a, b]: vp) {
            c += s.order_of_key(b);
            s.erase(b); // Optional, erasing after counting
        }

        cout << c << endl;
    }
}