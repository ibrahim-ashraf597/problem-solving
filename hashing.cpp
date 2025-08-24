const int bs1 = 131, bs2 = 137, M1 = 1e9 + 7, M2 = 1e9 + 11;
int pw1[N], pw2[N];
int mul(int x, int y, int MOD) {
    return(((x % MOD) * (y % MOD)) % MOD);
}
void  init() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pw1[i] = mul(pw1[i - 1], bs1, M1);
        pw2[i] = mul(pw2[i - 1], bs2, M2);
    }

}

int add(int x, int y, int MOD) {
    return(((x % MOD) + (y % MOD)) % MOD);
}
class hashing {
private:
    vector<pair<int, int>>pr;
public:
    hashing(const string& a) {
        int h1 = 0, h2 = 0;
        for (int i = 0; i < a.size(); i++) {
            int x = a[i];
            h1 = add(mul(h1, bs1, M1), x, M1);
            h2 = add(mul(h2, bs2, M2), x, M2);
            pr.push_back({ h1,h2 });
        }

    }
    pair<int, int>get(int l, int r) {
        auto ret = pr[r];
        int sz = r - l + 1;
        if (l) {
            ret.first = (ret.first - mul(pr[l - 1].first, pw1[sz], M1) + M1) % M1;
            ret.second = (ret.second - mul(pr[l - 1].second, pw2[sz], M2) + M2) % M2;
        }
        return ret;
    }
};