struct FenwickTree {
    int n;
    vector<int> bit;


    FenwickTree(int n) : n(n) {
        bit.assign(n + 1, 0);
    }


    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }


    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }


    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};
