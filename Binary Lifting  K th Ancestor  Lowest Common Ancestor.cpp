
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