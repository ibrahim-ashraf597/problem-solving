#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

long long mod_exp(long long a, long long b, long long m) {
    long long res = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}
bool miller_rabin(long long n, int k) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    long long m = n - 1;
    int d = 0;
    while (m % 2 == 0) {
        m /= 2;
        d++;
    }

    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4);
        long long x = mod_exp(a, m, n);

        if (x == 1 || x == n - 1) continue;

        bool ok = false;
        for (int r = 0; r < d - 1; r++) {
            x = (x * x) % n;
            if (x == n - 1) {
                ok = true;
                break;
            }
        }

        if (!ok) return false;
    }
    return true;
}

int main() {
    long long n;
    int k;
    cin >> n >> k;
    /// k عدد الاخبتارات اللي هعملها 
    // طبعا كل لما ال k تزيد يبقي افضل
    if (miller_rabin(n, k)) {
        cout << n << " is prime";
    }
    else {
        cout << n << " is not prime";
    }

    return 0;
}

