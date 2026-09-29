 
class dynamic_sos {
private:
    int l_size, r_size;
    // Dimensions swapped: [upper_mask][exact_lower_bits]
    vector<vector<int64_t> > a, b;
    // freq[mask] tracks total elements where z_upper is a supermask of 'mask'
    vector<int64_t> freq;
 
public:
    dynamic_sos(int k) {
        l_size = k / 2;
        r_size = k - l_size;
        a.resize(1 << r_size,
                 vector<int64_t>(1 << l_size, 0));
        b.resize(1 << r_size,
                 vector<int64_t>(1 << l_size, 0));
        freq.resize(1 << r_size, 0);
    }
 
    void add(int x, int64_t val = 1) {
        int x_lower = x & ((1 << l_size) - 1);
        int x_upper = x >> l_size;
        for (int mask = 0; mask < (1 << r_size); mask++) {
            // If x_upper is a submask of 'mask'(mask >= x_upper)
 
            if ((mask & x_upper) == x_upper) {
                a[mask][x_lower] += val;
            }
            // If 'mask' is a submask of x_upper(mask <= x_upper)
            if ((mask & x_upper) == mask) {
                b[mask][x_lower] += val;
                freq[mask] += val;
            }
        }
    }
 
    int64_t submask_sum(int x) {
        int x_lower = x & ((1 << l_size) - 1);
        int x_upper = x >> l_size;
        int64_t ans = 0;
        // a[x_upper][y] perfectly holds sum of elements where z_upper <= x_upper
        // We just iterate over valid exact lower parts(y <= x_lower)
        for (int y = 0; y < (1 << l_size); y++) {
            if ((y & x_lower) == y) {
                ans += a[x_upper][y];
            }
        }
        return ans;
    }
 
    int64_t supermask_sum(int x) {
        int x_lower = x & ((1 << l_size) - 1);
        int x_upper = x >> l_size;
        int64_t ans = 0;
        // b[x_upper][y] perfectly holds sum of elements where z_upper >= x_upper
        // We just iterate over valid exact lower parts(y >= x_lower)
        for (int y = 0; y < (1 << l_size); y++) {
            if ((y & x_lower) == x_lower) {
                ans += b[x_upper][y];
            }
        }
        return ans;
    }
 
    int max_and(int x) {
        if (freq[0] == 0)
            return -1; // No elements inserted
 
        int x_lower = x & ((1 << l_size) - 1);
        int x_upper = x >> l_size;
 
        // 1. Maximize upper AND
        // Loop over all possible upper masks to find the highest achievable AND.
 
        int mx_upper = 0;
        for (int mask = 0; mask < (1 << r_size); mask++) {
            if (freq[mask] > 0) {
                mx_upper = max(mx_upper, mask & x_upper);
            }
        }
        // 2. Maximize lower AND
        // b[mx_upper][y] counts elements with EXACT lower part 'y' whose
        // upper part contains 'mx_upper' as a submask.
 
        int mx_lower = 0;
        for (int y = 0; y < (1 << l_size);
             y++) {
            if (b[mx_upper][y] > 0) {
                mx_lower = max(mx_lower, y &
                                         x_lower);
            }
        }
        return (mx_upper << l_size) | mx_lower;
    }
};
