void solve(){
    vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; i++) {
        std::cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
    }
  // How to input a graph with weights
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[u].push_back(make_pair(w, v));
    E[v].push_back(make_pair(w, u));
  }


    ////
    // iterating the matrix is all the 4 directions 
    // for matrix int a = i * k + j ; 
    // for converting the 2-d matrix into 1d
    vector<std::pair<int, int>> moves{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
     for (auto [dx, dy] : moves) {
                int nx = x + dx;
                int ny = y + dy;
                 if(a[nx][ny] > x ){
                 }
             }   
     }
