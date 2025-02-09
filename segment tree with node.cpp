struct node {
    int mx1; int mx2;
    node() {
        mx1 = 0, mx2 = 0;
    }
    node(int m1, int m2)
    {
        mx1 = m1; mx2 = m2;

    }
};
node marge(node a, node b)
{
    node h;
    vector<int>v;
    v.push_back(a.mx1);
    v.push_back(a.mx2);
    v.push_back(b.mx1);
    v.push_back(b.mx2);
    sort(all(v));
    h.mx1 = v[3];
    h.mx2 = v[2];
    return h;
}
struct segtree {

    int size; vector<node>sum;

    void init(int n)
    {
        size = 1; while (size < n)size *= 2;
        sum.assign(2 * size, node());
    }
    void set(int i, node v, int x, int lx, int rx)
    {
        if (rx - lx == 1) {
            sum[x] = v;
            return;
        }
        int m = ((lx + rx) / 2);
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        sum[x] = marge(sum[2 * x + 1], sum[2 * x + 2]);
    }
    void set(int i, node v)
    {
        set(i, v, 0, 0, size);
    }
    void build(vector<node>& a)
    {
        build(a, 0, 0, size);
    }
    void build(vector<node>& a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())sum[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        sum[x] = marge(sum[2 * x + 1], sum[2 * x + 2]);
    }
    node  sums(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)return node();
        if (lx >= l && rx <= r)return sum[x];
        int m = (lx + rx) / 2;
        node left_subtree = sums(l, r, 2 * x + 1, lx, m);
        node rigth_subtree = sums(l, r, 2 * x + 2, m, rx);
        return marge(left_subtree, rigth_subtree);
    }
    node  sums(int l, int r)
    {
        return sums(l, r, 0, 0, size);
    }
};