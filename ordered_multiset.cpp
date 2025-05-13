#include <iostream>
#include <vector>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_multiset = tree<pair<T, T>, null_type, less<pair<T, T>>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int temoz = 1;
    // cin >> temoz;

    while (temoz--) {
        int n, q; cin >> n >> q;
        vector<int>a(n);
        map<int, int>m;
        ordered_multiset<int> st;
        for (int i = 0; i < n; i++)cin >> a[i], m[i] = a[i], st.insert({ a[i],i });
        while (q--) {
            char op;
            cin >> op;
            if (op == '!') {
                int k, x;
                cin >> k >> x;
                k--;
                st.erase(st.find({ m[k], k }));
                m[k] = x;
                st.insert({ x, k });
            }
            else {
                int x, y;
                cin >> x >> y;
                int cnt = st.order_of_key({ y + 1, 0 }) - st.order_of_key({ x, 0 });
                cout << cnt << '\n';
            }

        }
    }



    return 0;
}