vector<int> kmp(string a) {
    int n = a.size();
    vector<int>pi(n);

    for (int i = 1, j = 0; i < n; i++) {
        while (j && a[i] != a[j])
            j = pi[j - 1];// abxxxxabx
        if (a[i] == a[j])
            j++;
        pi[i] = j;
    }
    return pi;
}



int Matching(vector<int>d1,vector<int>d2) {
    int n=d1.size(),m=d2.size();
    int j=0,ans=0;auto p=kmp(d2);
    for (int i=0;i<n;i++) {
        while (j>0&&d1[i]!=d2[j]) {
            j=p[j-1];
        }
        if (d1[i]==d2[j])
            j++;
        if (j==m) {
            ans++;
            j=p[j-1];
        }
    }
    return ans;
}
