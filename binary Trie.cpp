
struct BinaryTrie {
    struct node {
        node* ch[2];
        int fr[2];
        node() {
            fr[0] = fr[1] = 0;
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
            cur->fr[indx]++;
            cur = cur->ch[indx];
        }
    }
    void del(int n, int i, node* cur) {
        if (i == -1)
            return;
        bool idx = (n >> i) & 1;
        del(n, i - 1, cur->ch[idx]);
        cur->fr[idx]--;

        if (cur->fr[idx] == 0)
            delete cur->ch[idx], cur->ch[idx] = 0;

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