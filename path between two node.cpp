
vector<int> path_A_To_B(int a,int b,int &n, vector<vector<int> > &ad) {
    vector<int> d(n + 1, 1e9);vector<int>par(n+1,0);
    d[a] = 0;
    queue<int> q;
    vector<int>path;
    q.push(a);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int x: ad[u]) {
            if (d[x] == 1e9) {
                d[x] = d[u] + 1;
                par[x]=u;
                q.push(x);
            }
        }
    }
    int cur=b;
    while (d[cur]) {
        path.push_back(cur);
        cur=par[cur];
    }
    path.push_back(a);
    return path;
}
