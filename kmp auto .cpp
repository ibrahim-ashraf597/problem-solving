#include "bits/stdc++.h"

#define el '\n'
#define ll long long
//#define int  long long
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("unroll-loops")
using namespace std;
vector<int> kmp(string a) {
    int n = a.size();
    vector<int>pi(n);

    for (int i = 1, j = 0; i < n; i++) {
        while (j && a[i] != a[j])
            j = pi[j - 1];// abxxxxabx
        if (a[i] == a[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int pre[102][26];
const int N = 1e3 + 4, n2 = 104;
char v[N][N][n2][2];
bool dp[N][N][n2][2];
int n, m;
string a, b;
bool clc(int i,int j,int x,bool g) {
    if (x==m)
        return 1;
    if (j<i) {
        return (x==m);
    }
    auto &ret=dp[i][j][x][g];
    if (v[i][j][x][g])
        return ret;
    v[i][j][x][g]=1;
  //  cout<<i<<' '<<j<<' '<<x<<el;
  //  cout<<
    if (!g) {
        ret=clc(i+1,j,pre[x][a[i]-'a'],!g);
        ret|=clc(i,j-1,pre[x][a[j]-'a'],!g);
        return ret;
    }
    else {
        ret=clc(i+1,j,pre[x][a[i]-'a'],!g);
        ret=min(ret,clc(i,j-1,pre[x][a[j]-'a'],!g));
        return ret;
    }

}

void solve() {
    cin >> n >> m;
    cin >> a >> b;
    for (int i=0;i<m;i++)
        for (int j=0;j<26;j++)
            pre[i][j]=0;
    auto p=kmp(b);
    for (int i = 0; i <= m; i++) {
        for (int c = 0; c < 26; c++) {
            if (i < m && b[i] - 'a' == c) {
                pre[i][c] = i + 1;
            } else if (i > 0) {
                pre[i][c] = pre[p[i - 1]][c];
            }
        }
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int x = 0; x <= m; x++)
                for (int k=0;k<=2;k++)
                dp[i][j][x][k] = v[i][j][x][k] = 0;
    cout<<(clc(0,n-1,0,0)?"Saba7":"Wa7eed")<<el;
}

/*


*/
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // freopen("banana.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> T;
    // cin.ignore();

    for (int i = 1; i <= T; i++)
        solve();
}
