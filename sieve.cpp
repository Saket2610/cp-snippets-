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
