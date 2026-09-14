    int n;
    std::cin >> n;
    
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    const int X = rng() % 1000000000 + 123456;
    
    std::vector<i64> p(n);
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = mul(p[i - 1], X);
    }
    
    i64 sum = 0;
    std::vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> a[i];
        sum = (sum + p[a[i]]) % P;
    }
//
// The below code needs modulus as it gets too big 
    int n;
    std::cin >> n;
    
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    const int X = rng() % 1000000000 + 123456;
    
    std::vector<i64> p(n);
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = mul(p[i - 1], X);
    }
    i64 sum = 0 ;
    vector<int>a(n+1);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i < n ; i++){
        sum += a[i] * p[n-i-1];
    }
