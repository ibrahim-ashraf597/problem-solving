#include "bits/stdc++.h"
#define el '\n'
#define ll int
//#define int long long
#define Matrix vector<vector<int >>
#define Row vector<int >
using namespace std;
// صدقني لسه بحاول
// انت عارف المشكله مش فيا
// السفاح مش عايز يذاكر توبيك
// وتيموس بيحاول يقنعه انو مينفعش لازم تذاكر
// المهم اتخانقوا
// والسفاح قال لتيموس هنشوف مين فينا الصح
// والان انفصلوا وتيموس بيذاكر توبيك والسفاح بيحل جريدي وبس
const int N=2e5+5;
int freq[N],val[N];;vector<int>a(N);int ans=0;
void remove(int idx) {
    if (freq[a[idx]]==val[a[idx]])
        ans--;
    freq[a[idx]]--;
    if (freq[a[idx]]==val[a[idx]])
        ans++;
};
void add(int idx) {
    if (freq[a[idx]]==val[a[idx]])
        ans--;
    freq[a[idx]]++;
    if (freq[a[idx]]==val[a[idx]])
        ans++;
};
int get_answer() {
     return ans;
};

int block_size=500;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> q) {
    vector<int> answers(q.size());
    sort(q.begin(), q.end());


    int cur_l = 0;
    int cur_r = -1;

    for (Query q : q) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}
void solve() {
     int n,q;
    cin>>n>>q;
    int id=1;map<int,int>m;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        if (!m[a[i]]) {
            m[a[i]]=id++;
        }
        val[m[a[i]]]=a[i];
        a[i]=m[a[i]];
     }
    vector<Query>qeury(q);
    for (int i=0;i<q;i++) {
        cin>>qeury[i].l>>qeury[i].r;
        qeury[i].l--;qeury[i].r--;
        qeury[i].idx=i;
    }
     auto v=mo_s_algorithm(qeury);
     for (auto x:v)
         cout<<x<<el;

}


/*


 */
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;

    // freopen("milk.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cin >> T;
    for (int i = 1; i <= T; i++)
        solve();
}
