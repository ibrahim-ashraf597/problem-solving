struct segtree {
    int size; vector<int>sum;
    void init(int n)
    {
        size = 1; while (size < n)size *= 2;
        sum.assign(2 * size, 0);

    }

    void set(int i, int v, bool c, int x, int lx, int rx)
    {
        if (rx - lx == 1) {
            sum[x] = v; return;
        }
        int m = ((lx + rx) / 2);
        if (i < m)
        {
            set(i, v, c ? 0 : 1, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, c ? 0 : 1, 2 * x + 2, m, rx);
        }
        sum[x] = c ? (sum[2 * x + 1] | sum[2 * x + 2]) : (sum[2 * x + 1] ^ sum[2 * x + 2]);

    }
    void set(int i, int v, bool c)
    {
        set(i, v, c, 0, 0, size);
    }
    void build(vector<int>& a, bool  c)
    {
        build(a, c, 0, 0, size);
    }
    void build(vector<int>& a, bool c, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            if (lx < (int)a.size())sum[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, c ? 0 : 1, 2 * x + 1, lx, m);
        build(a, c ? 0 : 1, 2 * x + 2, m, rx);
        sum[x] = c ? (sum[2 * x + 1] | sum[2 * x + 2]) : (sum[2 * x + 1] ^ sum[2 * x + 2]);
    }
    int  sums(int v, int l, int x, int lx, int rx)
    {
        if (sum[x] < v || rx <= l)return -1;
        if (rx - lx == 1)return lx;
        int m = (lx + rx) / 2;
        int res = sums(v, l, 2 * x + 1, lx, m);
        if (res == -1)
        {
            res = sums(v, l, 2 * x + 2, m, rx);
        }
        return res;

    }
    int  sums(int k, int l)
    {
        return sums(k, l, 0, 0, size);
    }
    int find_number_of_element_greater_than(int l, int r, int x, int lx, int rx)
    {
        // if (rx - lx == 1)return sum[x];
        if (lx >= r || l >= rx)return 0;
        if (l <= lx && r >= rx)return sum[x];
        int m = (lx + rx) / 2;
        int left = find_number_of_element_greater_than(l, r, 2 * x + 1, lx, m);
        int rigth = find_number_of_element_greater_than(l, r, 2 * x + 2, m, rx);
        return left + rigth;
    }
    int find_number_of_element_greater_than(int l, int r)
    {
        return find_number_of_element_greater_than(l, r, 0, 0, size);

    }

    int find_the_element_with_end_vector(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) / 2;
        if (sum[2 * x + 2] > k)
        {
            return find_the_element_with_end_vector(k, 2 * x + 2, m, rx);
        }
        else   return find_the_element_with_end_vector(k - sum[2 * x + 2], 2 * x + 1, lx, m);

    }
    int find_the_element_with_end_vector(int k)
    {
        return find_the_element_with_end_vector(k, 0, 0, size);
    }
    int  sum_of_range(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)return 0;
        if (lx >= l && rx <= r)return sum[x];
        int m = (lx + rx) / 2;
        int left_subtree = sum_of_range(l, r, 2 * x + 1, lx, m);
        int rigth_subtree = sum_of_range(l, r, 2 * x + 2, m, rx);
        return left_subtree + rigth_subtree;
    }
    int  sum_of_range(int l, int r)
    {
        return sum_of_range(l, r, 0, 0, size);
    }

    int xor_of_range(int l, int r)
    {
        return xor_of_range(l, r, 0, 0, size);
    }
    int xor_of_range(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)return 0;
        if (lx >= l && rx <= r)return sum[x];
        int m = (lx + rx) / 2;
        int left = xor_of_range(l, r, 2 * x + 1, lx, m);
        int rigth = xor_of_range(l, r, 2 * x + 2, m, rx);
        return left ^ rigth;
    }
    int find_element_greter_than(int v)
    {
        return find_element_greter_than(v, 0, 0, size);

    }
    int find_element_greter_than(int v, int x, int lx, int rx)
    {
        if (rx - lx == 1) {
            sum[x] -= v;
            return rx;
        }
        int m = (lx + rx) / 2;

        if (sum[2 * x + 1] >= v)
        {
            int left = find_element_greter_than(v, 2 * x + 1, lx, m);
            sum[x] = max(sum[2 * x + 1], sum[2 * x + 2]);
            return left;
        }
        else  if (sum[2 * x + 2] >= v)
        {
            int rigth = find_element_greter_than(v, 2 * x + 1, lx, m);
            sum[x] = max(sum[2 * x + 1], sum[2 * x + 2]);
            return rigth;
        }
        else return 0;
    }
    int find_number_of_one(int v) {
        return find_number_of_one(v, 0, 0, size);
    }
    int find_number_of_one(int v, int x, int lx, int rx) {
        if (rx - lx == 1) {

            return lx;
        }
        int m = (lx + rx) / 2;
        if (sum[2 * x + 1] >= v) {
            return find_number_of_one(v, 2 * x + 1, lx, m);

        }
        else {

            return find_number_of_one(v - sum[2 * x + 1], 2 * x + 2, m, rx);
        }

    }
    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l)return;
        if (lx >= l && rx <= r) {
            sum[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);

    }
    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }
    int get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) return sum[x];
        int m = (lx + rx) / 2; int res;
        if (i < m)res = get(i, 2 * x + 1, lx, m);
        else res = get(i, 2 * x + 2, m, rx);
        return res + sum[x];
    }
    int get(int i) {
        return  get(i, 0, 0, size);
    }
    void add_MAX_in_range(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l)return;
        if (lx >= l && rx <= r) {
            sum[x] = max(sum[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        add_MAX_in_range(l, r, v, 2 * x + 1, lx, m);
        add_MAX_in_range(l, r, v, 2 * x + 2, m, rx);

    }
    void add_MAX_in_range(int l, int r, int v) {
        add_MAX_in_range(l, r, v, 0, 0, size);
    }
    int get_MAX(int i, int x, int lx, int rx) {
        if (rx - lx == 1) return sum[x];
        int m = (lx + rx) / 2; int res;
        if (i < m)res = get_MAX(i, 2 * x + 1, lx, m);
        else res = get_MAX(i, 2 * x + 2, m, rx);
        return max(res, sum[x]);
    }
    int get_MAX(int i) {
        return  get_MAX(i, 0, 0, size);
    }

    int  sum_of_range_with_bitmask(int l, int r, bool c, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)return 0;
        if (lx >= l && rx <= r)return sum[x];
        int m = (lx + rx) / 2;
        int left_subtree = sum_of_range_with_bitmask(l, r, c ? 0 : 1, 2 * x + 1, lx, m);
        int rigth_subtree = sum_of_range_with_bitmask(l, r, c ? 0 : 1, 2 * x + 2, m, rx);
        // sum[x] = c ? (sum[2 * x + 1] | sum[2 * x + 2]) : (sum[2 * x + 1] ^ sum[2 * x + 2]);

        return c ? left_subtree | rigth_subtree : left_subtree ^ rigth_subtree;
    }
    int  sum_of_range_with_bitmask(int l, int r, bool c)
    {
        return sum_of_range_with_bitmask(l, r, c, 0, 0, size);
    }

};