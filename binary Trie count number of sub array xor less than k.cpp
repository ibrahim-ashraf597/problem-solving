// وَإِن تَعْجَبْ فَعَجَبٌ قَوْلُهُمْ أَإِذَا كُنَّا تُرَابًا أَإِنَّا لَفِي خَلْقٍ جَدِيدٍ
#include "bits/stdc++.h"
#define ll long long 
#define el '\n'
#define int ll
using namespace std;
const int N = 1e6 + 5, n22 = 501, mod = 1e9 + 7, M = 1e9 + 7, base = 31;
int k;
struct BinaryTrie {
    struct node {
        node* ch[2];
        int cnt = 0;
        node() {

            ch[0] = ch[1] = 0;

        }
    };
    node* root = new node();
    void insert(int n) {
        node* cur = root;
        for (int i = 31; i >= 0; i--) {
            bool indx = (n >> i) & 1ll;
            if (cur->ch[indx] == 0) {
                cur->ch[indx] = new node();
            }
            cur->cnt++;
            cur = cur->ch[indx];
        }
    }

    int query(int n) {
        node* cur = root; int ans = 0;
        for (int i = 31; i >= 0; i--) {
            bool idx = ((n >> i) & 1), idxk = ((k >> i) & 1);
            if (idxk) {
                if (cur->ch[idx] != 0)
                    ans += cur->ch[idx]->cnt;
                if (cur->ch[!idx] == 0)
                    break;
                cur = cur->ch[!idx];
            }
            else
            {
                if (cur->ch[idx] == 0)
                    break;
                cur = cur->ch[idx];
            }
        }
        return ans;
    }

    int MxXor(int n) {
        node* cur = root; int val = 0;
        for (int i = 31; i >= 0; i--) {
            bool idx = (n >> i) & 1;
            if (cur->ch[1 ^ idx] != 0) {
                val += (1ll << i);
                cur = cur->ch[1 ^ idx];
            }
            else {
                cur = cur->ch[idx];
            }
        }
        // if(cur->)
        return val;

    }
};
void solve() {
    int n; cin >> n >> k;
    BinaryTrie tr;
    vector<int>a(n), pr(n);
    tr.insert(0);

    int c = 0;
    for (int i = 0; i<n && cin >> a[i]; pr[i] = a[i], i ? pr[i] ^= pr[i - 1] : 0, i++);
    for (int i = 0; i < n; i++) {

        c += tr.query(pr[i]);
        tr.insert(pr[i]);
    }
    cout << c << el;

}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
