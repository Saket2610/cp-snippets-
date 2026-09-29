vector<int> minp, primes; 
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

std::vector<std::vector<int>> divs(m + 1);
for (int i = 1; i <= m; i++)
    for (int j = i; j <= m; j += i)
        divs[j].push_back(i);
// divs[x] stores all divisors of x. Used to iterate over common divisors of pairs.




/// prime factorization 
vector<int> vx(N + 1);
vector<std::vector<int>> e(N + 1);
// Take x = 12 = 2² · 3¹.
// After this, used = [2, 3], vx[2] = 2, vx[3] = 1.
void factor(int x, auto f) {
    while (x > 1) {
        int p = minp[x];
        int c = 0;
        while (x % p == 0) {
            x /= p;
            c++;
        }
        f(p, c);
    }
}

vector<int> used;
auto use = [&](int p) {
    if (vx[p] == 0 && e[p].empty()) {
        used.push_back(p);
    }
};
factor(x, [&](int p, int c) {
    use(p);
    vx[p] = c;
});
