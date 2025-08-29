struct Trie {
    struct node {
        int pre; int end;
        node* ch[26];
        node() {
            pre = 0; end = 0;
            memset(ch, 0, sizeof ch);
        }
    };
    node* root = new node();
    void insert(string s) {
        node* cur = root;
        for (auto it : s) {
            int idx = it - 'a';
            if (cur->ch[idx] == 0) {
                cur->ch[idx] = new node();
            }
            cur = cur->ch[idx];
            cur->pre++;
        }
        cur->end++;
    }
    int count(string s) {
        node* cur = root;
        for (auto it : s) {
            int idx = it - 'a';
            if (cur->ch[idx] == 0) {
                return 0;
            }
            cur = cur->ch[idx];

        }
        return cur->pre;
    }
};