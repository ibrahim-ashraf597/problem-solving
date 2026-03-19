#include "bits/stdc++.h"
#define el '\n'
#define ll long long
#define int long long
#define Matrix vector<vector<int >>
#define Row vector<int >
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mxs = -1e18, mns = 1e18, mxd = -1e18, mnd = 1e18;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mxs = max(mxs, (x + y));
        mns = min(mns, (x + y));
        mxd = max(mxd, (x - y));
        mnd = min(mnd, (x - y));
    }
    cout<<max(abs(mxs-mns),abs(mnd-mxd));
}


/*


 */
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;

    // freopen("milk.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //  cin >> T;

    for (int i = 1; i <= T; i++)
        solve();
}
