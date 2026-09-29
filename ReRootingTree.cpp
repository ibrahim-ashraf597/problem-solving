// ويتمني لو تاتي مرة

#include "bits/stdc++.h"
#define el '\n'
#define ll long long
#define int long long
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("unroll-loops")
using namespace std;



struct ReRootingTree {
    const int N = 2e5 + 5;
    vector<int>dp,ans;
   vector<vector<int>>ad;
    ReRootingTree(int n) {
        ans=vector<int>(n+4);
        dp=vector<int>(n+4);
        ad=vector<vector<int>>(n+4);

    }
    void add(int x,int y) {
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
    void cal(int root) {
        pre(root,0);
        dfs(root,0,0);
    }
    void pre(int u,int p) {
        for (int x:ad[u])if (x!=p) {
            pre(x,u);
            dp[u]=max(dp[u],dp[x]+1);
        }
    }
    void dfs(int u,int p,int ans_par) {
        ans[u]=max(dp[u],ans_par);
        multiset<int>s;
        for (int x:ad[u])if (x!=p) {
            s.insert(dp[x]);
        }
        for (int x:ad[u])if (x!=p) {
            s.erase(s.find(dp[x]));
            int mx=ans_par+1;
            if (s.size())
                mx=max(mx,*s.rbegin()+2);
            dfs(x,u,mx);
            s.insert(dp[x]);
        }

    }
};
void solve() {
    int n;
    cin >> n;
    ReRootingTree tree(n);
    for (int i=0;i<n-1;i++) {
        int x,y;cin>>x>>y;
       tree.add(x,y);
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
