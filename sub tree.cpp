
vector<vector<int>> ad(N + 1);
vector<int> sub(N);

void sub_tree(int root, int p) {
    sub[root] = 1;
    for (int v : ad[root]) {
        if (v == p) continue;
        sub_tree(v, root);
        sub[root] += sub[v];
    }
}

