
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

ll power(ll b, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1)
            ret = (ret * b) % mod;
        b *= b, b %= mod, p >>= 1;
    }
    return ret;
}
