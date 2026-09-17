// ويتمني لو تاتي مرة

#include "bits/stdc++.h"
#define el '\n'
#define ll long long
#define int long long
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("unroll-loops")
using namespace std;
using namespace std;
const int B=20,N=1LL<<B;
int dp[N],dp2[N];
bool on(int mask,int i) {
    return (mask>>i)&1;
}
void solve() {
int n;cin>>n;
    vector<int>a(n);
    for (int i=0;i<n;i++) {
        int x;cin>>x;
        dp[x]++;
        dp2[x]++;
        a[i]=x;
    }
    // submask
    for (int bit=0;bit<B;bit++) {
        for (int mask=0;mask<N;mask++) {
            if (on(mask,bit))
                dp[mask]+=dp[mask^(1<<bit)];

        }
    }
    // super mask
    for (int bit=0;bit<B;bit++) {
        for (int mask=N-1;mask!=-1;mask--) {
            if (on(mask,bit))
                dp2[mask^(1<<bit)]+=dp2[mask];

        }
    }
    for (int i=0;i<n;i++) {
        // bitset<20>b((N-1)^a[i]);
        // cout<<b<<el;
        // b=(a[i]);
        // cout<<b<<el;
        cout<<dp[a[i]]<<' '<<dp2[a[i]]<<' '<<n-dp[(N-1)^a[i]]<<el;

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
