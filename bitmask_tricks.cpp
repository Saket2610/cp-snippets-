int la = a & -a;
// lowest set bit (1010 --> 2 (10)
-a = ~a + 1 --> fact 

a / la = odd part of a 

__builtin_parity(s) ? 1 : -1 
// __builtin_parity(s) returns 1 if number of 1's in s is odd → determines sign in inclusion-exclusion.

__builtin_ctz(16) = 4;
// 10000


// Declares 100005 bits, all initialized to 0
bitset<100005> f{};
f[500] = 1;
f.set(100000); 
cout << f[500] << std::endl; // Output: 1
cout << f.size() << std::endl; // Output: 100005


//
int binaryToInt(string binary) {
    return stoi(binary, nullptr, 2);
}
cout << binaryToInt("0010");   // 2
// stoi  31 bits
// stol  31/63 bits
// stoll 63 bits // safest 

string a ; cin>>a;
std::vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        A[i] = a[i] - '0';
        B[i] = b[i] - '0';
    }
