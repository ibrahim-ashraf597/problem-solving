// ويتمني لو تاتي مرة

#include "bits/stdc++.h"

#define el '\n'
#define ll long long
#define int  long long
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("unroll-loops")

using namespace std;

struct DSU {
private:
public:
    vector<int> par, size,dis;
    DSU(int n) {
        par.resize(n + 5);
        dis.resize(n + 5);
        size.resize(n + 5, 1);
        std::iota(par.begin(), par.end(), 0);
    }

    int getRoot(int u) {
        if (u == par[u])return u;
        int root=getRoot(par[u]);
        dis[u]+=dis[par[u]];
        return par[u] = root;
    }

    bool sameSet(int u, int v) {
        return getRoot(u) == getRoot(v);
    }

    void merge(int u, int v,int w =1) {
        u = getRoot(u);
        v = getRoot(v);
        if (u == v)
            return;
       /// if (size[u] > size[v]) swap(u, v);
        par[u] = v;
        size[v] += size[u];
        dis[u]=w;
    }
};
void solve() {
    int n,m;cin>>n>>m;
    DSU d(n);
    for (int i=0;i<m;i++) {
        int op;
        cin>>op;
        if (op==1) {
            int x,y;cin>>x>>y;
            d.merge(x,y);
        }
        else {
            int x;cin>>x;
            d.getRoot(x);
            cout<<d.dis[x]<<el;
        }
    }
}


/*



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
