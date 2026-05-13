// Elements are stored in sorted order (ascending by default)
// Operations like insert, delete, search run in O(log n)

void solve(){
    std::set<int> f{0}, s, a;
    auto it = a.end();
    // iterator points to the element not the index 
    // 
    a.insert(d);
    // Common operations
    s.find(5);       // returns iterator to 5, or s.end() if not found    
    s.count(2);      // returns 1 (exists) or 0 (not found)
    s.erase(5);      // removes element
    s.size();        // number of elements
    s.empty();       // true if empty

    set<int> s = {10, 20, 30, 40};

    // 1. Classic iterator loop
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";   // dereference with *
    }

    // 2. Auto (cleaner syntax)
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }

    // 3. Range-based for (simplest)
    for (auto val : s) {
        cout << val << " ";
    }

    // Output: 10 20 30 40

    auto it = s.begin();

    ++it;        // move forward
    --it;        // move backward (bidirectional iterators)
    *it;         // dereference — get the value
    it != s.end() // check if we've reached the end
      
    auto it = s.find(30);
    if (it != s.end()) {
        cout << "Found: " << *it;  // Found: 30
    }

    set<int> s = {10, 20, 30};
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << " ";
    }
    // Output: 30 20 10
  
}
