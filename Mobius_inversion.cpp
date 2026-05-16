void solve(){
  
    int mu[m + 1] = {};
    mu[1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 2 * i; j <= m; j += i) {
            mu[j] -= mu[i];
        }
    }
    // μ(n)=(−1)^k n is product of k distinct primes
    // μ(n)=0 n has a squared prime factor
    // μ(1)=1 Base case
  
}
