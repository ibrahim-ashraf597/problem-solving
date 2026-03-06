#include "bits/stdc++.h"
#define el '\n'
#define ll int
#define int long long
#define Matrix vector<vector<int >>
#define Row vector<int >
using namespace std;
mt19937_64 rng(time(nullptr));
// صدقني لسه بحاول
// انت عارف المشكله مش فيا
// السفاح مش عايز يذاكر توبيك
// وتيموس بيحاول يقنعه انو مينفعش لازم تذاكر
// المهم اتخانقوا
// والسفاح قال لتيموس هنشوف مين فينا الصح
// والان انفصلوا وتيموس بيذاكر توبيك والسفاح بيحل جريدي وبس

const int N = 1e9 + 4;

struct Node {
    ll val{};
    Node *left, *right;

    Node() {
    }

    Node(int val) : val(val) {
    }

    Node(Node *l, Node *r) {
        left = l;
        right = r;
        if (left)val += left->val;
        if (right)val += right->val;

    }
};

struct PST {

    Node *update(Node *node, int lx, int rx, int i,int val) {
        if (lx == rx) return new Node((node ? node->val : 0) + val);

        int m = lx + (rx - lx) / 2;
        Node *l = (node ? node->left : nullptr);
        Node *r = (node ? node->right : nullptr);

        if (i <= m)
            return new Node(update(l, lx, m, i,val), r);
        else
            return new Node(l, update(r, m + 1, rx, i,val));
    }
    ll query(Node *node, int lx, int rx, int l, int r) {
        if (!node || lx > r || rx < l) return 0;
        if (l <= lx && rx <= r) return node->val;

        int m = lx + (rx - lx) / 2;
        return query(node->left, lx, m, l, r) +
            query(node->right, m + 1, rx, l, r);
    }

    Node *update(Node *k, int i, int x) {
        return update(k, 0, N, i, x);
    }

    ll query(Node *k, int l, int r) {
        return query(k, 0, N, l, r);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Node *> root;
    PST p;
    root.push_back(nullptr);
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        root.push_back(p.update(root.back(), a[i], 1));
    }
    int q;
    cin >> q;
    while (q--) {
        int A, B, K;
        cin >> A >> B >> K;
        A = A ^ ans;
        B = B ^ ans;
        K = K ^ ans;
        if (A < 1)
            A = 1;
        if (B > n)B = n;
        if (A > B) {
            cout << 0 << el;
            ans = 0;
        } else {
            int l = A, r = B;
            ans=p.query(root[r], K + 1, N)
            - p.query(root[l - 1], K + 1, N) ;
            cout << ans<< el;
        }
    }
}

/*
 */
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // freopen("milk.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    /// cin >> T;
    for (int i = 1; i <= T; i++)
        solve();
}
