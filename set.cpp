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
    set<int> s = {10, 20, 30, 40, 50};


    
    auto lb = s.lower_bound(30);  // first element >= 30 → points to 30
    auto ub = s.upper_bound(30);  // first element >  30 → points to 40
    auto eq = s.equal_range(30);  // returns pair<iterator, iterator> → {lb, ub}

    cout << *lb;        // 30
    cout << *ub;        // 40
    cout << *eq.first;  // 30
    cout << *eq.second; // 40
  /////
    /////
    /////
    std::set<int> s = {10, 20, 30, 40, 50};

    auto it = s.begin(); // Points to 10

    // Get the next element (20)
    auto it_next = std::next(it); 
    
    // Get the element 2 positions ahead (30)
    auto it_plus_2 = std::next(it, 2); 

    // Get the last element (50) by going back from end()
    auto it_last = std::prev(s.end());

    std::cout << "Next: " << *it_next << "\n";      // Output: 20
    std::cout << "Plus 2: " << *it_plus_2 << "\n";  // Output: 30
    std::cout << "Last: " << *it_last << "\n";      // Output: 50
}
