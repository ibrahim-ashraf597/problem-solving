array<int, 3> getDia(vector<vector<int>> &adj)
{
    pair<int, int> dia = {0, 0};

    function<void(int, int, int)> dfs = [&](int u, int p, int d)
    {
        if (d > dia.first)
            dia = {d, u};

        for (int v : adj[u])
        {
            if (v == p)
                continue;

            dfs(v, u, d + 1);
        }
    };

    dfs(1, 0, 0);
    int a = dia.second;
    dia = {0, 0};
    dfs(a, 0, 0);
    int b = dia.second;

    int dis = dia.first;

    return {a, b, dis};
}
