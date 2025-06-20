vector< vector<int> > ad(N), components;
vector<int> inStack(N), lowLink(N), compNum(N), inDeg(N);
stack<int> stk;
int timer;
bool f = 0;
void tarjan(int u, int p) {
    lowLink[u] = inDeg[u] = ++timer, inStack[u] = 1;
    stk.push(u);
    for (auto& i : ad[u]) {
        if (!inDeg[i]) {
            tarjan(i, u);
            lowLink[u] = min(lowLink[u], lowLink[i]);
            if (lowLink[i] == inDeg[i]) {
                f = 1;
            }
        }
        else if (i != p) {
            lowLink[u] = min(lowLink[u], inDeg[i]);
        }
    }
}
vector<int>vis(N);
map<pair<int, int>, bool>mp;
void build(int u) {
    vis[u] = 1;
    for (int x : ad[u]) {
        if (!mp[{x, u}]) {
            cout << u << ' ' << x << el;
            mp[{x, u}] = 1;
            mp[{u, x}] = 1;
        }
        if (!vis[x])build(x);
    }
}