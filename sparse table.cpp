int n, T[N][32] = {}, Log[N]; vector<int>a(N);
int merge(int a, int  b) {
    return min(a, b);
}
void build() {
    for (int i = 0; i < n; i++)
        T[i][0] = a[i];
    for (int pw = 1; (1 << pw) <= n; pw++) {
        for (int i = 0; i + (1 << pw) <= n; i++) {
            T[i][pw] = merge(T[i][pw - 1], T[i + (1 << (pw - 1))][pw - 1]);
        }
    }

    return;
}
int query(int l, int r) {
    int sz = (r - l + 1); int ret = 0;
    for (int i = 32; i >= 0; i--)
    {
        if (((sz >> i) & 1)) {
            ret = merge(ret, T[l][i]); l += (1 << i);
        }
    }
    return ret;
}
void preCount() {
    Log[1] = 0;
    for (int i = 2; i < N; i++)
        Log[i] = Log[i / 2] + 1;

}