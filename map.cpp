void solve(){
    map<vector<int> , int> tree;
    if(tree.contains(a)){}


    // multimap has the initial order of ascending order 
    // same as map
    multimap<int,int> mp;
    multimap<int, int>::iterator itr;

    mp.insert({5, 10});
    // mp[key] might give earror in multimap coz multiple values exists for same key 
    // mp[key] works in map coz no duplicates 

    auto it = mp.find(5);
    // Returns iterator to first occurrence of key 5
    mp.erase(it);
    
    
    mp.count(5);
    // Returns number of elements with key 5

    auto it = mp.lower_bound(5);
    // Returns iterator to first element ≥ key

    auto it = mp.upper_bound(5);
    // Returns iterator to first element > key

    auto it = mp.end();
    it--;
    x = it->second;
    // returns an iterator pointing one position after the last element

    mp.erase(key);
    // removes ALL entries with that key

    auto it = mp.begin();
    


    
}
