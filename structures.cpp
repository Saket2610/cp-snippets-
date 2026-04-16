
void solve(){

    int n;
    cin>>n;
    vector vec(2 , vector<int>(n));
    vector<vector<int>> vec1(2 , vector<int>(n));
   

    vector<int> a[n];
    // n - vectors 

    vector<int> a(n);
    // 1 - vector of size n ; 

    vector<int> a(n,0);
    // 1 -vector of size n all initally 0 ;


    const int n = 5;
    vector<array<int, n>> vec2(2, array<int, n>{});
    // only works with constant(means no input)


    const int n = 5;
    vector<array<int,n>> vec2(2);
    // it means 2 rows and n columns same as above 
    // cant take input too 

    vector<vector<array<int,2>>> adj(n);
    // for saving edges of the graph with index
    // adj[u].push_back({v , i});

    int m; 
    cin>>m;
    int a[m][m];
    // can take input 
}
