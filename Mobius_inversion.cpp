void solve(){
  
    int mu[m + 1] = {};
    mu[1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 2 * i; j <= m; j += i) {
            mu[j] -= mu[i];
        }
    }
  
}
