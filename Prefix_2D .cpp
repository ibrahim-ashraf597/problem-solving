struct Prefix_2D {

    int n, m;
    vector < vector < ll > > prefix;

    Prefix_2D(int N = 0, int M = 0) {
        n = N, m = M;
        prefix.assign(n + 20, vector < ll >(m + 20));
    }
    ll Get_Query(int x1, int y1, int x2, int y2) {
         if (x1 > x2) swap(x1, x2);
         if (y1 > y2) swap(y1, y2);
        return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
    }

    void Build_Prefix(vector < vector < ll > >& matrix) {

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                prefix[i][j] = matrix[i][j] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
    }

    void Print_Prefix() {
        for (int i = 1; i <= n; i++, cout << '\n')
            for (int j = 1; j <= m && cout << prefix[i][j] << ' '; j++);
    }
};
