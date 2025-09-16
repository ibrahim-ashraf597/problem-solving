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