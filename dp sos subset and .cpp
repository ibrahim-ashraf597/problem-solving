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
ll power(ll n, ll p, ll mod) {
    if (p == 0)
        return 1;
 
    ll a = power(n, p / 2, mod);
    a = (a * a) % mod;
 
    if (p % 2 == 1)
        return (a * (n % mod)) % mod;
    else
        return a;
}
 
const int B = 20, N = 1LL << B, M = 1e9 + 7;
int dp[N],g[N];
 
bool on(int mask,int i) {
    return (mask >> i) & 1;
}
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dp[x]++;
    }
    // super mask
    for (int bit = 0; bit < B; bit++) {
        for (int mask = N - 1; mask != -1; mask--) {
            if (on(mask, bit))
                dp[mask ^ (1 << bit)] += dp[mask];
        }
    }
    for (int mask = N - 1; mask != -1; mask--) {
        g[mask] = power(2, dp[mask], M) - 1 + M;
        g[mask] %= M;
    }
    for (int bit = 0; bit < B; bit++) {
        for (int mask = N - 1; mask != -1; mask--) {
            if (!on(mask, bit))
                g[mask] = (g[mask] - g[mask | (1 << bit)] + M) % M;
        }
    }
    for (int i = 0; i <= n; i++)
        cout << g[i] << ' ';
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
