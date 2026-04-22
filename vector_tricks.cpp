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
    
}
