#include "bits/stdc++.h"
#define el '\n'
#define ll long long
#define int long long
#define Matrix vector<vector<ll>>
#define Row vector<ll>
using namespace std;
// داخل انا والسفاح علشان بدا يخيب ومش هينفع كده
//   تيموس فضل يقوله هتخيب وهو يقول لا
//   بس خلاص تيموس اقنع السفاح
// احذر يا تيموس


const long long MOD = 1e9 + 7;

Matrix mul(const Matrix &a, const Matrix &b) {
    int n = a.size();
    int m = b[0].size();
    int p = b.size();

    Matrix res(n, Row(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < p; ++k) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]);
                res[i][j] += MOD;


                // while (res[i][j]>=MOD)
                res[i][j] %= MOD;
            }
        }
    }

    return res;
}

Matrix power(Matrix a, int b) {
    int n = a.size();
    Matrix res(n, Row(n));

    for (int i = 0; i < n; ++i)
        res[i][i] = 1;

    while (b) {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }

    return res;
}

vector<int> dp(10, -1);
int clc(int i) {
    if (i == 0)
        return 1;
    int &ret = dp[i];
    if (~ret)
        return ret;
    ret = 0;
    for (int j = 1; j <= 6; j++)
        if (i >= j)
            ret += clc(i - j);
    return ret;
}
/*


sad=last_sad*20+last_happy*7
happy =last_happy*19+last_sad*  6
 **/
void solve() {
    int n;
    cin >> n;
    Matrix s = {{0,1}};

    Matrix t={{20,6},{7,19}};

    auto ans = power(t, n);
    ans= mul(s,ans);
    cout<<ans[0][1];
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
