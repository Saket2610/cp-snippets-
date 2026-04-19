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


    reverse(a.begin() , a.end());
    //reverse the vector 
    vector<int> reversed_v(v.rbegin(), v.rend()); 
    // Creates a reversed copy


    rotate(a.begin(), a.begin() + x, a.end());
    // rotate the array left shift by x units

    rotate(a.begin(), a.begin() - x, a.end());
    // rotate the array right shift by x units
}
