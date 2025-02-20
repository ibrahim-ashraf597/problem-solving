int n; cin >> n;  int q; cin >> q;
vector<vector<char>>v(n + 1, vector<char>(n + 1));
f1(i, n)f1(j, n)cin >> v[i][j];

vector<vector<int>>a(n + 1, vector<int>(n + 1));
f1(i, n) {
    f1(j, n) {
        char x = v[i][j];

        a[i][j] = (x == '*');
    }
}


f1(i, n)a[i][1] = a[i][1] + a[i - 1][1];
f1(j, n)a[1][j] = a[1][j] + a[1][j - 1];

for (int i = 2; i <= n; i++)
for (int j = 2; j <= n; j++)
a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int c = a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] - a[x1 - 1][y1 - 1];
    cout << c << '\n';
}