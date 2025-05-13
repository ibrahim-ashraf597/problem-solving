
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
vector<int>fact(N + 4), factinv(N + 4);
void pre() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        fact[i] = ((i % M) * (fact[i - 1] % M)) % M;
    }
    factinv[N - 1] = power(fact[N - 1], M - 2, M);;
    for (int i = N - 2; i >= 0; i--)
        factinv[i] = (factinv[i + 1] % M * (i + 1) % M) % M;
}
int ncr(int n, int r) {
    return (((fact[n] % M * factinv[n - r] % M) % M) * factinv[r] % M) % M;
}
int s_b(int st, int b) {
    return ncr(st + b, st);
}