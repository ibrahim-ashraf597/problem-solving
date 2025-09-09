// وَإِن تَعْجَبْ فَعَجَبٌ قَوْلُهُمْ أَإِذَا كُنَّا تُرَابًا أَإِنَّا لَفِي خَلْقٍ جَدِيدٍ
#include "bits/stdc++.h"
#define ll long long 
#define el '\n'
#define int ll
using namespace std;
int k;
struct BinaryTrie {
    struct node {
        node* ch[2];
        int cnt = 0;
        int fr[2];
        node() {
            fr[0] = fr[1] = 0;
            ch[0] = ch[1] = 0;

        }
    };
    node* root = new node();
    void insert(int n) {
        node* cur = root;
        cur->cnt++;
        for (int i = 63; i >= 0; i--) {
            bool indx = (n >> i) & 1ll;
            if (cur->ch[indx] == 0) cur->ch[indx] = new node();
            cur->fr[indx]++;
            cur = cur->ch[indx];
            cur->cnt++;
        }
    }
    void del(int n, int i, node* cur) {
        if (i == -1)
        {
            cur->cnt--;
            return;
        }
        bool idx = (n >> i) & 1;
        del(n, i - 1, cur->ch[idx]);
        cur->fr[idx]--;
        cur->cnt--;
        if (cur->fr[idx] == 0)
            delete cur->ch[idx], cur->ch[idx] = 0;

    }
    int query(int n) {
        node* cur = root; int ans = 0;
        for (int i = 63; i >= 0; i--) {
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

};

void solve() {
    int n; BinaryTrie tr;
    cin >> n;
    while (n--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            tr.insert(x);
        }
        else if (op == 2) {
            int x; cin >> x;
            tr.del(x, 63, tr.root);
        }
        else {
            int x, li;
            cin >> x >> li; k = li;
            cout << tr.query(x) << el;;
        }

   }


}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T = 1;
   //  cin >> T;
    while (T--) solve();
}
