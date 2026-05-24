void solve(){
    vector<int> rev;
    vector<int> x;

    rev.insert(rev.end(), x.begin(), x.end());
    // adds vector x at the end of vector rev 

    iota(p[j].begin(), p[j].end(), 0);
    // fill the vector p with 0 

     if (std::count(A.begin(), A.end(), 1) == 0) {
        std::cout << -1 << "\n";
        return;
    }
    // searching for specific element in vector 
    
    std::sort(p[i].begin(), p[i].end(),
            [&](int x, int y) {
                return a[x][i] < a[y][i];
            });
    // stores index of sorted order of a 
    // a remains unchanged 

    vector<std::array<int, 2>> a(n);
    std::sort(a.begin(), a.end(),
        [&](auto x, auto y) {
            return x[0] + x[1] < y[0] + y[1];
        });
    // sort by min sum a[0][i] and a[1][i] 



    
    reverse(a.begin() , a.end());
    //reverse the vector 
    vector<int> reversed_v(v.rbegin(), v.rend()); 
    // Creates a reversed copy


    rotate(a.begin(), a.begin() + x, a.end());
    // rotate the array left shift by x units

    rotate(a.begin(), a.begin() - x, a.end());
    // rotate the array right shift by x units

    int x = ranges::min_element(a) - a.begin();
    // index of the minimum element in the array a 

    int x = a.back();
    // asscessing the index of the last element / recently pushed element

    a.pop_back();
    // removing the last element from vector a

    a.resize(n);
    // changes the size of vector a to n 
    // if a has extra elements more than n --> it automatically removes it;

    array<int, 10> myarray;
    myarray.fill(1); // Assigns 1 to every element

    a.erase(unique(a.begin(), a.end()), a.end());
    // removing unique elements from vector a

    if (std::find(a.begin(), a.end(), target) != a.end()) {
    // Found the index of first matching element 
    }


    // tuple and vector
    vector<tuple<int, int, int>> endpoints;
    get<0>(endpoints[i])
    // to get the first element in tuple

    tuple<int, int, int> f2[10][10], f3[10][10][10];
    f2[s[j] - '0'][s[j + 1] - '0'] = {j + 1, j + 2, i + 1};
      if (i + 2 <= m && f2[s[i] - '0'][s[i + 1] - '0'] != std::tuple(0, 0, 0)) 
          // checking if it contains in tuple 

}
