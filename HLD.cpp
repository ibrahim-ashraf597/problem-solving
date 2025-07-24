
struct HLD {
    vector<int>sz, big, par, head, id, dep;
    void dfs(int v, const vector<vector<int>>& ad) {
        for (auto x : ad[v]) {
            if (x == par[v]) continue;
            par[x] = v;
            dep[x] = dep[v] + 1;
            dfs(x, ad);
            sz[v] += sz[x];
            if (big[v] == 0 || sz[x] > sz[big[v]])
                big[v] = x;

        }
    }
    void fllatan(int v, const vector<vector<int>>& ad, int& next) {
        id[v] = next++;
        if (big[v])
            head[big[v]] = head[v], fllatan(big[v], ad, next);
        for (int x : ad[v]) {
            if (x == par[v] || x == big[v])continue;
            head[x] = x;
            fllatan(x, ad, next);
        }
    }
    vector<pair<int, int>>path(int u, int v) {
        vector<pair<int, int>>res;
        while (1) {
            if (head[u] == head[v]) {
                if (dep[u] > dep[v])
                    swap(u, v);
                res.push_back({ id[u],id[v] });
                return res;
            }
            if (dep[head[u]] > dep[head[v]])
                swap(u, v);
            res.push_back({ id[head[v]], id[v] });
            v = par[head[v]];
        }

    }
    HLD(int n, const vector<vector<int>>& ad) :big(n + 1), par(n + 1), sz(n + 1, 1), head(n + 1, 1), id(n + 1), dep(n + 1) {
        dfs(1, ad);
        int next = 0;
        head[1] = 1;
        fllatan(1, ad, next);
    }
};
