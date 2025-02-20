vector<int> insertion_sort(vector<int>a, int n) {
    for (int j = 1; j < n; j++) {
        int i = j - 1; int key = a[j];
        while (i >= 0 && key < a[i]) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;

    }
    return a;
}