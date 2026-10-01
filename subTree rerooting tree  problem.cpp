// ويتمني لو تاتي مرة

#include "bits/stdc++.h"
#define el '\n'
#define ll long long
#define int long long
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("unroll-loops")
using namespace std;

const int N = 2e5 + 5;
vector<int> ad[N];
const int M=1e9+7;
int mul(int x,int y) {
    return (x % M * y % M) % M;
}

int add(int x,int y) {
    return (x % M + y % M) % M;
}

struct ReRootingTree {
    vector<int> ans, sz;
    int n;
    vector<int> dp;

    ReRootingTree(int n) {
        this->n = n;
        ans = vector<int>(n + 4, 1e18);
        sz = vector<int>(n + 4);
        //ad = vector<vector<int> >(n + 4);
        dp = vector<int>(n + 4, 1);
    }

    void add(int x,int y) {
        ad[x].push_back(y);
        ad[y].push_back(x);
    }

    void cal(int root) {
        pre(root, 0);
        dfs(root, 0, 0);
    }
    void pre(int u,int p) {
        sz[u] = 1;dp[u]=1;
        for (int x: ad[u])
            if (x != p) {
                pre(x, u);
                sz[u] += sz[x];
                dp[u] = mul(dp[u], dp[x] + 1);
            }
    }


    void dfs(int u, int p, int sum_par) {
        ans[u]=mul(dp[u],(sum_par+1));

        vector<int>pre;
        vector<int>suff;
        int idx=0;
        map<int,int>m;
        for (int x:ad[u])if (x!=p) {
           pre.push_back(dp[x]+1);
           suff.push_back(dp[x]+1);
            m[x]=idx++;
        }
int sz=suff.size();
        for (int i=1;i<pre.size();i++)
            pre[i]=mul(pre[i],pre[i-1]);
        for (int i=sz-2;i>=0;i--)
            suff[i]=mul(suff[i],suff[i+1]);

        for (int x:ad[u])if (x!=p) {
             int o=1,pos=m[x];
             if (pos)
                 o=mul(o,pre[pos-1]);
            if (pos!=suff.size()-1)
                o=mul(o,suff[pos+1]);
            dfs(x,u,mul(o,sum_par+1));
        }
    }
};



void solve() {
    int n;
    cin >> n;    ReRootingTree tree(n);
    for (int i=2;i<=n;i++) {
        int x;cin>>x;
        ad[i].push_back(x);
        ad[x].push_back(i);
    }
    tree.cal(1);
    for (int i=1;i<=n;i++)
        cout<<tree.ans[i]<<' ';



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
