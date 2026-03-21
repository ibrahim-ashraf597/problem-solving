
struct FG {
    int n, LOG;
    vector<int> to, vis, in_cycle, dist;
    vector<vector<int>> up;

    FG(int n) : n(n) {
        LOG = 30;
        to.resize(n + 1);
        vis.assign(n + 1, 0);
        in_cycle.assign(n + 1, 0);
        dist.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG));
    }

    void add_edge(int u, int v) {
        to[u] = v;
    }

    void dfs(int u) {
        vis[u] = 1;
        int v = to[u];

        if (!vis[v]) {
            dfs(v);
            dist[u] = dist[v] + 1;
        }
        else if (vis[v] == 1) {
            int cur = v;
            do {
                in_cycle[cur] = 1;
                dist[cur] = 0;
                cur = to[cur];
            } while (cur != v);
            dist[u] = dist[v] + 1;
        }
        else {
            dist[u] = dist[v] + 1;
        }

        vis[u] = 2;
    }

    void build() {
        for (int i = 1; i <= n; i++)
            up[i][0] = to[i];

        for (int j = 1; j < LOG; j++)
            for (int i = 1; i <= n; i++)
                up[i][j] = up[up[i][j - 1]][j - 1];

        for (int i = 1; i <= n; i++)
            if (!vis[i]) dfs(i);
    }

    int jump(int u, long long k) {
        for (int i = 0; i < LOG; i++)
            if (k & (1LL << i))
                u = up[u][i];
        return u;
    }
};

void solve() {
    int n; cin >> n;
    FG g(n);
    int q; cin >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        g.add_edge(i, x);
    }
    g.build();

    while (q--) {
        int u, k;
        cin >> u >> k;
        cout << g.jump(u, k) << '\n';
    }
}

