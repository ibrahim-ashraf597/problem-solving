#include <bits/stdc++.h>
#define ll long long

using namespace std;

class segment_tree
{
    struct node
    {
        int mn = 2e9;
        int mx = -2e9;

        int ans = 2e9;
        int cnt = 0;

        void merge(node l, node r)
        {
            mn = min(l.mn, r.mn);
            mx = max(l.mx, r.mx);

            ans = min(l.ans, r.ans);
            cnt = max(l.cnt, r.cnt);

            if (l.cnt > 0 && r.cnt > 0)
                ans = min(ans, l.mx ^ r.mn);
        }

        void apply(int i, int val)
        {
            if (val < 0)
            {
                if (--cnt == 0)
                {
                    mn = 2e9;
                    mx = -2e9;
                }
            }
            else
            {
                mn = val;
                mx = val;
                cnt++;
            }
        }
    };

    int size = 1;
    vector<node> tree;

    void update(int x, int lx, int rx, int idx, int val)
    {
        if (lx == rx)
        {
            tree[x].apply(idx, val);
            return;
        }

        int mid = (lx + rx) / 2;
        int left = 2 * x + 1;
        int right = 2 * x + 2;

        if (idx <= mid)
            update(left, lx, mid, idx, val);
        else
            update(right, mid + 1, rx, idx, val);

        tree[x].merge(tree[left], tree[right]);
    }

    node query(int x, int lx, int rx, int l, int r)
    {
        if (l <= lx && rx <= r)
            return tree[x];
        if (lx > r || l > rx)
            return node();

        int mid = (lx + rx) / 2;
        int left = 2 * x + 1;
        int right = 2 * x + 2;

        node L = query(left, lx, mid, l, r);
        node R = query(right, mid + 1, rx, l, r);

        node ret;
        ret.merge(L, R);

        return ret;
    }

public:
    segment_tree(int n)
    {
        while (size < n)
            size *= 2;

        tree = vector<node>(2 * size - 1);
    }

    void update(int idx, int val)
    {
        update(0, 0, size - 1, idx, val);
    }

    node query(int l, int r)
    {
        return query(0, 0, size - 1, l, r);
    }
};

struct query
{
    int op, l, r;
};

void solve()
{
    int q;
    cin >> q;

    vector<int> vals;
    vector<query> quer(q);

    for (int i = 0; i < q; i++)
    {
        cin >> quer[i].op;

        if (quer[i].op == 3)
        {
            cin >> quer[i].l >> quer[i].r;
        }
        else
        {
            cin >> quer[i].l;
            vals.push_back(quer[i].l);
        }
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();

    segment_tree seg(m);

    for (int i = 0; i < q; i++)
    {
        auto [op, a, b] = quer[i];
        int idx = lower_bound(vals.begin(), vals.end(), a) - vals.begin();

        if (op == 1)
            seg.update(idx, a);
        else if (op == 2)
            seg.update(idx, -1);
        else
        {
            a = lower_bound(vals.begin(), vals.end(), a) - vals.begin();
            b = upper_bound(vals.begin(), vals.end(), b) - vals.begin() - 1;

            if (a > b)
            {
                cout << -1 << "\n";
            }
            else
            {
                auto x = seg.query(a, b);

                if (x.cnt > 1)
                    cout << 0 << "\n";
                else if (x.ans == 2e9)
                    cout << -1 << "\n";
                else
                    cout << x.ans << "\n";
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    if (fopen(".input.txt", "r"))
    {
        freopen(".input.txt", "r", stdin);
        freopen(".output.txt", "w", stdout);
    };

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
