// ويتمني لو تاتي مرة

#include "bits/stdc++.h"
#define el '\n'
#define ll long long
#define int  long long
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("unroll-loops")

using namespace std;

// @prefix LazySegment
// @description

class SegmentTree {
private:
    int size = 1;

    struct Node {
        ll sum, lazy;

        Node() : sum(-1e18), lazy(0) {}
        Node(ll val) : sum(val), lazy(0) {}

        void apply(int lx, int rx, ll val) {
            sum += val ;
            lazy += val;
        }

        void merge(const Node& lf, const Node& ri) {
            sum = max(lf.sum , ri.sum);
        }
    };

    vector<Node> seg;

    void propagate(int nd, int lx, int rx) {
        if (seg[nd].lazy == 0) return;

        if (lx != rx) {
            int mid = (lx + rx) >> 1, lf = 2 * nd + 1, ri = 2 * nd + 2;
            seg[lf].apply(lx, mid, seg[nd].lazy);
            seg[ri].apply(mid + 1, rx, seg[nd].lazy);
        }
        seg[nd].lazy = 0;
    }

    void build(int nd, int lx, int rx, vector<int>& a) {
        if (lx == rx) {
            if (lx < a.size()) {
                seg[nd] = Node(a[lx]);
            }
            return;
        }

        int mid = (lx + rx) >> 1, lf = 2 * nd + 1, ri = 2 * nd + 2;
        build(lf, lx, mid, a);
        build(ri, mid + 1, rx, a);
        seg[nd].merge(seg[lf], seg[ri]);
    }

    void update(int nd, int lx, int rx, int l, int r, ll val) {
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r) {
            seg[nd].apply(lx, rx, val);
            return;
        }

        propagate(nd, lx, rx);
        int mid = (lx + rx) >> 1, lf = 2 * nd + 1, ri = 2 * nd + 2;
        update(lf, lx, mid, l, r, val);
        update(ri, mid + 1, rx, l, r, val);
        seg[nd].merge(seg[lf], seg[ri]);
    }

    Node query(int nd, int lx, int rx, int l, int r) {
        if (lx > r || rx < l) return Node();
        if (lx >= l && rx <= r) return seg[nd];

        propagate(nd, lx, rx);
        int mid = (lx + rx) >> 1, lf = 2 * nd + 1, ri = 2 * nd + 2;

        Node ret;
        ret.merge(query(lf, lx, mid, l, r), query(ri, mid + 1, rx, l, r));
        return ret;
    }

public:
    SegmentTree(vector<int>& a) {
        while (size < a.size())
            size <<= 1;
        seg.assign(2 * size, Node());
        build(0, 0, size - 1, a);
    }

    void update(int l, int r, ll val) {
        update(0, 0, size - 1, l, r, val);
    }

    ll query(int l, int r) {
        return query(0, 0, size - 1, l, r).sum;
    }
};

int clc(int n) {
    int mx = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if ((i & j) == 0) {
                cout << i << ' ' << j << el;
                mx = max(mx, gcd(i, j));
            }
    return mx;
}

const int N = 3e5 + 5;
vector<int> ad[N];
int timer = 1;
int in[N], inChild[N], sz[N];

void Temos_eular(int u,int p) {
    sz[u] = 1;
    inChild[u] = timer + 1;
    for (int x: ad[u])
        if (x != p) {
            in[x] = ++timer;
        }
    for (int x: ad[u])
        if (x != p) {
            Temos_eular(x, u);
            sz[u] += sz[x];
        }
}

void solve() {
    int n,q;
    cin >> n>>q;
    in[1] = 1;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
    Temos_eular(1, 0);
    // for (int i=1;i<=n;i++)cout<<i<<' ';cout<<el;
    // for (int i=1;i<=n;i++)cout<<in[i]<<' ';cout<<el;
    // for (int i=1;i<=n;i++)cout<<inChild[i]<<' ';cout<<el;

    vector<int>a(timer+5);
    SegmentTree sg(a);
    while (q--) {
        int op;cin>>op;
        if (op==1) {
            int x,v;cin>>x>>v;
            sg.update(in[x],in[x],v);
            if (sz[x]>1) {
                sg.update(inChild[x],inChild[x]+sz[x]-2,v);
            }
        }
        else if (op==2) {
            int x,v;cin>>x>>v;
            if (sz[x]-1>0) {
                sg.update(inChild[x],inChild[x]+ad[x].size()-(x==1?1:2),v);
            }
        }
        else if (op==3) {
            int x;cin>>x;
             int mx= sg.query(in[x],in[x]);
            if (sz[x]>1) {
                mx=max(mx,sg.query(inChild[x],inChild[x]+sz[x]-2));
            }
            cout<<mx<<el;
        }
        else {
            int x;cin>>x;
            int mx=-1e18;
            if (sz[x]-1>0) {
                mx=max(mx,sg.query(inChild[x],inChild[x]+ad[x].size()-(x==1?1:2)));
            }
            cout<<mx<<el;

        }
    }
}


/*


7
1 2
1 3
2 4
2 5
5 6
5 7



*/
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;

    // freopen("milk.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // cin >> T;

    for (int i = 1; i <= T; i++)
        solve();
}
