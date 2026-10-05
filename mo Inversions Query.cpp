// ويتمني لو تاتي مرة

#include "bits/stdc++.h"
#define el '\n'
#define ll long long
#define int long long
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("unroll-loops")
using namespace std;
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
const int N=1e5+10;int n;
int val[N];;vector<int>a(N);int ans=0;int q;
FenwickTree sg (N);int v[N];
void remove(int idx,int u) {
    int x=v[idx];
    sg.update(x,-1);
    if (u) {
        if (x+1<=n)
            ans-=sg.query(x+1,n);
    }
    else {
        if (x-1>0)
            ans-=sg.query(1,x-1);
    }
};
///0 L   1 R
void add(int idx,int u) {
   int x=v[idx];
    sg.update(x,1);
    if (u) {
      if (x+1<=n)
          ans+=sg.query(x+1,n);
    }
    else {
        if (x-1>0)
        ans+=sg.query(1,x-1);
    }
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
            add(cur_l,0);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r,1);
        }
        while (cur_l < q.l) {
            remove(cur_l,0);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r,1);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}
void solve() {

    cin>>n>>q;
    vector<int>a(n);
    vector<int>so;map<int,int>m;
    for (int i=0;i<n;i++) {
        cin>>a[i];
      if (!m[a[i]])so.push_back(a[i]),m[a[i]]=1;
    }
    sort(so.begin(),so.end());m.clear();
    for (int i=0;i<n;i++) {
        v[i]=lower_bound(so.begin(),so.end(),a[i])-so.begin()+1;
    }
    vector<Query>qeury(q);
    for (int i=0;i<q;i++) {
        cin>>qeury[i].l>>qeury[i].r;
        //qeury[i].l--;
        qeury[i].r--;
        qeury[i].idx=i;
    }
    auto v=mo_s_algorithm(qeury);
    for (auto x:v)
        cout<<x<<el;

}


/*

a^2+b^2=c^2


*/
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;

    // freopen("milk.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // cin >> T;

    for (int i = 1; i <= T; i++)
        solve();
}
