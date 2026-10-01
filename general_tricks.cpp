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
    cout << "GCD: " << gcd(a, b) << "\n";   // Output: 6 

    
    
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    int a = rng();
        
}
