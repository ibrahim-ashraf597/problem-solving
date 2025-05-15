const int N = 1e6 + 5, n2 = 1e3 + 55;

int n, T[N][32] = {}, Log[N]; vector<int>a(N,1e18);
int merge(int a, int  b) {
    return min(a, b);
}
void build() {
    for (int i = 0; i < n; i++)
        T[i][0] = a[i];
    for (int pw = 1; (1ll << pw) <= n; pw++) {
        for (int i = 0; i + (1ll << pw) <= n; i++) {
            T[i][pw] = merge(T[i][pw - 1], T[i + (1ll << (pw - 1))][pw - 1]);
        }
    }

    return;
}
int query(int l, int r) {
    int len = r - l + 1;
    int k = Log[len];
    return merge(T[l][k], T[r - (1ll << k) + 1][k]);
}

void preCount() {
    Log[1] = 0;
    for (int i = 2; i < N; i++)
        Log[i] = Log[i / 2] + 1;

}
