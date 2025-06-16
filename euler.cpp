int timer = 0;
vector<int>in(N), out(N); vector<int>ad[N];
void dfs(int u, int p) {
    in[u] = ++timer;
    for (auto x : ad[u])
        if (p != x)
            dfs(x, u);

    out[u] = ++timer;

};