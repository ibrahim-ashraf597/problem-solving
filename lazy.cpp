#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cstdint>
#include <unordered_map>
#include <bitset>
#include <cstring>


#define ll long long 
#define i128 __int128_t
#define pb push_back
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define el '\n';
#define temos int64_t
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define ON(n, k) ((n) | (1 << k))
#define off(n, k) ((n) & (~(1 << k)))
#define ison(n, k) ((n >> k) & 1)
#define int long long 
#define all(a) a.begin(),a.end()

using namespace std;


int dx[] = { 1,-1 ,0 ,0 };
int dy[] = { 0 ,0,1 ,-1 };

struct segtreelazy {
    int size;
    vector<int> sum, lazy;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2 * size, 0);
        lazy.assign(2 * size, 0);
    }
    void propegate(int l, int r, int x) {
        if (lazy[x] == 0)return;
        if (r - l > 1) {
            lazy[2 * x + 1] += lazy[x];
            lazy[2 * x + 2] += lazy[x];
        }
        sum[x] += lazy[x];
        lazy[x] = 0;
    }
    void build(vector<int>& a) {
        build(a, 0, 0, size);
    }

    void build(vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) sum[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        sum[x] = min(sum[2 * x + 1], sum[2 * x + 2]);
    }

    void  update(int l, int r, int v, int x, int lx, int rx) {
        propegate(lx, rx, x);
        if (rx <= l || r <= lx)return;
        if (lx >= l && rx <= r) {
            lazy[x] += v;
            propegate(lx, rx, x);
            return;
        }
        int  m = (lx + rx) / 2;
        update(l, r, v, 2 * x + 1, lx, m);
        update(l, r, v, 2 * x + 2, m, rx);
        sum[x] = min(sum[2 * x + 1], sum[2 * x + 2]);
    }
    void  update(int l, int r, int v) {
        update(l, r, v, 0, 0, size);
    }
    int query(int l, int r, int x, int lx, int rx) {
        propegate(lx, rx, x);
        if (rx <= l || r <= lx)return 1e18;
        if (lx >= l && rx <= r) {
            return sum[x];

        }
        int  m = (lx + rx) / 2;
        int left = query(l, r, 2 * x + 1, lx, m);
        int rigth = query(l, r, 2 * x + 2, m, rx);;
        sum[x] = min(sum[2 * x + 1], sum[2 * x + 2]);
        return min(left, rigth);
    }
    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};
string subtract_one(string a) {
    reverse(all(a)); int n = a.size();
    f0(i, n) {
        if (a[i] != '0') {
            if (i == 0) {
                a[0]--; break;
            }

        }
    }
    reverse(all(a));
    return a;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int temoz = 1;
    // cin >> temoz;
    while (temoz--) {
        int n, q; cin >> n >> q;
        segtreelazy t; t.init(n);
        vector<int>a(n, 0);
        t.build(a);
        while (q--) {
            int op; cin >> op;
            if (op == 1) {
                int l, r, v; cin >> l >> r >> v;
                t.update(l, r, v);
                // cout << "ssls\n";
            }
            else {
                int l, r;
                cin >> l >> r;
                cout << t.query(l, r) << "\n";
            }
        }
    }

    return 0;
}