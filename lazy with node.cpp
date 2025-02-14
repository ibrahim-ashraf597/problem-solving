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
const int M = 1e9 + 7;

int dx[] = { 1,-1 ,0 ,0 };
int dy[] = { 0 ,0,1 ,-1 };
struct node {
    int sum, mx, pre, su;
    node() {
        sum = 0; mx = 0; pre = 0; su = 0;
    }
    node(int sum1, int mx1, int pre1, int su1) :sum(sum1), mx(mx1), pre(pre1), su(su1) {

    }
};
node marge(node a, node b) {
    node h;
    h.sum = a.sum + b.sum;
    h.pre = max(a.pre, a.sum + b.pre);
    h.su = max(b.su, b.sum + a.su);
    h.mx = max({ a.mx,b.mx,a.su + b.pre });
    return h;

}
const int sk = 1e10;
struct segtreelazy {
    int size; vector<node>sum; vector<int> lazy;
    void init(int n) {
        size = 1;
        while (size < n)size *= 2;
        sum.assign(2 * size, node());
        lazy.assign(2 * size, sk);
    }
    void build(vector<node>& a) {
        build(a, 0, 0, size);
    }
    void build(vector<node>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size())sum[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
    }
    void propegate(int l, int r, int x) {
        if (lazy[x] == sk)return;
        if (r - l > 1) {
            lazy[2 * x + 1] = lazy[x];
            lazy[2 * x + 2] = lazy[x];
        }
        int v = lazy[x];
        if (v >= 0) {
            sum[x].sum = (r - l) * v;
            sum[x].pre = (r - l) * v;
            sum[x].su = (r - l) * v;
            sum[x].mx = (r - l) * v;
        }
        else {
            sum[x].sum = (r - l) * v;
            sum[x].pre = 0;
            sum[x].su = 0;
            sum[x].mx = 0;
        }
        lazy[x] = sk;
    }
    void update(int l, int r, int v) {
        update(l, r, v, 0, 0, size);
    }
    void update(int l, int r, int v, int x, int lx, int rx) {
        propegate(lx, rx, x);
        if (lx >= r || l >= rx)return;
        if (lx >= l && rx <= r) {
            lazy[x] = v;
            propegate(lx, rx, x);
            return;
        }
        int m = (lx + rx) / 2;
        update(l, r, v, 2 * x + 1, lx, m);
        update(l, r, v, 2 * x + 2, m, rx);
        propegate(lx, rx, x);
        sum[x] = marge(sum[2 * x + 1], sum[2 * x + 2]);
    }
    node  query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
    node query(int l, int r, int x, int lx, int rx) {
        propegate(lx, rx, x);
        if (lx >= r || l >= rx)return node(0, 0, 0, 0);
        if (lx >= l && rx <= r) {

            return sum[x];
        }
        int m = (lx + rx) / 2;
        node left = query(l, r, 2 * x + 1, lx, m);
        node rigth = query(l, r, 2 * x + 2, m, rx);
        propegate(lx, rx, x);
        sum[x] = marge(sum[2 * x + 1], sum[2 * x + 2]);


        return marge(left, rigth);
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int temoz = 1;
    // cin >> temoz;
    while (temoz--) {
        int n, q; cin >> n >> q;
        vector<node>a;
        f0(i, n) {
            a.push_back(node(0, 0, 0, 0));
        }
        segtreelazy t; t.init(n); t.build(a);
        while (q--) {
            int l, r, v; cin >> l >> r >> v;;
            t.update(l, r, v);
            cout << t.sum[0].mx << "\n";
        }
    }

    return 0;
}