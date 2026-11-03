vector<int> a = {1, 5, 8, 12, 20};
    bitset<200> bit;
    bit[0] = 1;
    for (auto it : a)
    {
        bit |= bit << it;
    }
    vector<int> b = {2, 7, 90, 6, 1};
    bitset<200> bit2;
    bit2[0] = 1;
    for (auto it : b)
    {
        bit2 |= bit2 << it;
    }
    
    bitset<200> tem;
    for (int i = 1; i < 200; i++)
    {
        if (bit[i])
        {
            tem |= bit2 << i;
        }
    }
