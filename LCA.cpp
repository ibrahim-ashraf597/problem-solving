
const int Log = 23;
int   anc[N][Log], lvl[N]; vector<int >ad[N];
void build_ancestor(int node, int par) {

    ////
    lvl[node] = lvl[par] + 1;
    anc[node][0] = par;
    for (int i = 1; i < Log; i++) {
        int p = anc[node][i - 1];
        anc[node][i] = anc[p][i - 1];
    }


    ////
    for (auto x : ad[node]) {
        if (x != par) {
            build_ancestor(x, node);
        }
    }


}
int kthancestor(int node, int k) {
    for (int i = Log - 1; i >= 0; i--) {
        if ((k >> i) & 1)
            node = anc[node][i];
    }
    return node;
}
int LCA(int u, int v) {
    if (lvl[u] < lvl[v]) {
        swap(u, v);
    }
    u = kthancestor(u, lvl[u] - lvl[v]);
    // same level 
    if (u == v)return v;
    for (int i = Log - 1; i >= 0; i--) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[v][0];
}
int dis(int u, int v) {
    int lca = LCA(u, v);
    return lvl[u] + lvl[v] - 2 * lvl[lca];
}






struct LCA {
    int n, Log;
    vector<vector<int>> anc, ad;
    vector<int> lvl;

    LCA(int n) {
        this->n = n;
        Log = 23;
        anc.assign(n + 1, vector<int>(Log));
        ad.assign(n + 1, vector<int>());
        lvl.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        ad[u].push_back(v);
        ad[v].push_back(u);
    }

    void build(int node = 1, int par = 0) {
        lvl[node] = lvl[par] + 1;
        anc[node][0] = par;

        for (int i = 1; i < Log; i++) {
            int p = anc[node][i - 1];
            anc[node][i] = anc[p][i - 1];
        }

        for (auto x : ad[node]) {
            if (x != par) {
                build(x, node);
            }
        }
    }

    int kth(int node, int k) {
        for (int i = Log - 1; i >= 0; i--) {
            if ((k >> i) & 1)
                node = anc[node][i];
        }
        return node;
    }

    int lca(int u, int v) {
        if (lvl[u] < lvl[v]) swap(u, v);

        u = kth(u, lvl[u] - lvl[v]);

        if (u == v) return u;

        for (int i = Log - 1; i >= 0; i--) {
            if (anc[u][i] != anc[v][i]) {
                u = anc[u][i];
                v = anc[v][i];
            }
        }

        return anc[u][0];
    }

    int dist(int u, int v) {
        int L = lca(u, v);
        return lvl[u] + lvl[v] - 2 * lvl[L];
    }
};
