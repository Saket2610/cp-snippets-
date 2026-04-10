void solve(){
    vector<int> rev;
    vector<int> x;

    rev.insert(rev.end(), x.begin(), x.end());
    // adds vector x at the end of vector rev 

    iota(p[j].begin(), p[j].end(), 0);
    // fill the vector p with 0 

    
    std::sort(p[i].begin(), p[i].end(),
            [&](int x, int y) {
                return a[x][i] < a[y][i];
            });
    // stores index of sorted order of a 
    // a remains unchanged 
} 
