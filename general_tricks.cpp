void solve{

    // creating local scope
    {
        int x ; 
        cin>>x;
        cout<<x;
    }
    // here i dont know what x is 


    int a = 12, b = 18;
    std::cout << "LCM: " << std::lcm(a, b); // Output: 36

    int a = max_element(nums.begin(), nums.end()) - nums.begin();
    // returns the index of the max element

    int a = min_element(nums.begin(), nums.end()) - nums.begin();
    // returns the index of the min element 

    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    int a = rng();
        
}
