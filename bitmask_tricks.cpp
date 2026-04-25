int la = a & -a;
// lowest set bit (1010 --> 2 (10)
-a = ~a + 1 --> fact 

a / la = odd part of a 


// Declares 100005 bits, all initialized to 0
bitset<100005> f{};
f[500] = 1;
f.set(100000); 
cout << f[500] << std::endl; // Output: 1
cout << f.size() << std::endl; // Output: 100005
