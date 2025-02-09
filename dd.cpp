
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
struct DSU {
private:
    vector<int>par, size;
public:
    DSU(int n) {
        par.resize(n + 5);
        size.resize(n + 5, 1);
        std::iota(par.begin(), par.end(), 0);
    }
    int getRoot(int u) {
        if (u == par[u])return u;
        return par[u] = getRoot(par[u]);
    }
    bool sameSet(int u, int v) {
        return getRoot(u) == getRoot(v);
    }
    void merge(int u, int v) {
        u = getRoot(u);
        v = getRoot(v);
        if (u == v)
            return;
        par[u] = v;
        size[v] += size[u];
    }
};
struct segtree {
    int size; vector<int>sum;
    void init(int n)
    {
        size = 1; while (size < n)size *= 2;
        sum.assign(2 * size, 0);

    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1) {
            sum[x] = 0; return;
        }
        int m = ((lx + rx) / 2);
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
    void build(vector<int>& a)
    {
        build(a, 0, 0, size);
    }
    void build(vector<int>& a, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            if (lx < (int)a.size())sum[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
    }
    int  sums(int v, int l, int x, int lx, int rx)
    {
        if (sum[x] < v || rx <= l)return -1;
        if (rx - lx == 1)return lx;
        int m = (lx + rx) / 2;
        int res = sums(v, l, 2 * x + 1, lx, m);
        if (res == -1)
        {
            res = sums(v, l, 2 * x + 2, m, rx);
        }
        return res;

    }
    int  sums(int k, int l)
    {
        return sums(k, l, 0, 0, size);
    }
    int find_number_of_element_greater_than(int l, int r, int x, int lx, int rx)
    {
        // if (rx - lx == 1)return sum[x];
        if (lx >= r || l >= rx)return 0;
        if (l <= lx && r >= rx)return sum[x];
        int m = (lx + rx) / 2;
        int left = find_number_of_element_greater_than(l, r, 2 * x + 1, lx, m);
        int rigth = find_number_of_element_greater_than(l, r, 2 * x + 2, m, rx);
        return left + rigth;
    }
    int find_number_of_element_greater_than(int l, int r)
    {
        return find_number_of_element_greater_than(l, r, 0, 0, size);

    }

    int find_the_element_with_end_vector(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) / 2;
        if (sum[2 * x + 2] > k)
        {
            return find_the_element_with_end_vector(k, 2 * x + 2, m, rx);
        }
        else   return find_the_element_with_end_vector(k - sum[2 * x + 2], 2 * x + 1, lx, m);

    }
    int find_the_element_with_end_vector(int k)
    {
        return find_the_element_with_end_vector(k, 0, 0, size);
    }
    int  sum_of_range(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)return 0;
        if (lx >= l && rx <= r)return sum[x];
        int m = (lx + rx) / 2;
        int left_subtree = sum_of_range(l, r, 2 * x + 1, lx, m);
        int rigth_subtree = sum_of_range(l, r, 2 * x + 2, m, rx);
        return left_subtree + rigth_subtree;
    }
    int  sum_of_range(int l, int r)
    {
        return sum_of_range(l, r, 0, 0, size);
    }

    int xor_of_range(int l, int r)
    {
        return xor_of_range(l, r, 0, 0, size);
    }
    int xor_of_range(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)return 0;
        if (lx >= l && rx <= r)return sum[x];
        int m = (lx + rx) / 2;
        int left = xor_of_range(l, r, 2 * x + 1, lx, m);
        int rigth = xor_of_range(l, r, 2 * x + 2, m, rx);
        return left ^ rigth;
    }
    int find_element_greter_than(int v)
    {
        return find_element_greter_than(v, 0, 0, size);

    }
    int find_element_greter_than(int v, int x, int lx, int rx)
    {
        if (rx - lx == 1) {
            sum[x] -= v;
            return rx;
        }
        int m = (lx + rx) / 2;

        if (sum[2 * x + 1] >= v)
        {
            int left = find_element_greter_than(v, 2 * x + 1, lx, m);
            sum[x] = max(sum[2 * x + 1], sum[2 * x + 2]);
            return left;
        }
        else  if (sum[2 * x + 2] >= v)
        {
            int rigth = find_element_greter_than(v, 2 * x + 1, lx, m);
            sum[x] = max(sum[2 * x + 1], sum[2 * x + 2]);
            return rigth;
        }
        else return 0;
    }
    int find_number_of_one(int v) {
        return find_number_of_one(v, 0, 0, size);
    }
    int find_number_of_one(int v, int x, int lx, int rx) {
        if (rx - lx == 1) {

            return lx;
        }
        int m = (lx + rx) / 2;
        if (sum[2 * x + 1] >= v) {
            return find_number_of_one(v, 2 * x + 1, lx, m);

        }
        else {

            return find_number_of_one(v - sum[2 * x + 1], 2 * x + 2, m, rx);
        }

    }
};
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //#ifdef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //#endif
    int64_t temoz = 1;// cin >> temoz;
    while (temoz--) {
        int n; cin >> n; vector<int>a(n);
        f0(i, n)cin >> a[i]; vector<int>v(n, 1);
        segtree t; t.init(n);
        t.build(v);
        f0(i, n)cin >> v[i];
        f0(i, n) {
            //int x; cin >> x;
            int id = t.find_number_of_one(v[i]);
            t.set(id, 0);

            cout << a[id] << ' ';

        }
    }

    return 0;
}
