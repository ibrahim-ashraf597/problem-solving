const int N = 1e6 + 5, n22 = 501, mod = 1e9 + 7, M = 1e9 + 7, base = 31;

ll pw1[N], pw2[N];
const ll bs1 = 131, bs2 = 137, mod2 = 1e9 + 11;
void init() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw1[i] = pw1[i - 1] * bs1 % mod;
        pw2[i] = pw2[i - 1] * bs2 % mod2;
    }
}
struct Hash
{
private:
    vector<pair<int, int>> pre;

public:
    Hash(string& s) {
        pre.assign(s.size(), { 0, 0 });
        int h1 = 0, h2 = 0;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] + 1;
            h1 = (h1 * bs1 % mod + x) % mod;
            h2 = (h2 * bs2 % mod2 + x) % mod2;
            pre[i] = { h1, h2 };
        }
    }
    pair<int, int> get(int l, int r) {
        pair<int, int> ret = pre[r];
        int sz = r - l + 1;
        if (l) {
            ret.first = (ret.first - pre[--l].first * pw1[sz] % mod + mod) % mod;
            ret.second = (ret.second - pre[l].second * pw2[sz] % mod2 + mod2) % mod2;
        }
        return ret;

    }
};
