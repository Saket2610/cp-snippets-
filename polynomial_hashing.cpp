    //The below code is not polynomial hashing—this is randomized hashing/ XOR hashing / Sum Hashing 
    // Here The order of array does matter -> The array {2, 3 , 1 , 1} gives the same hash as {1 , 3 , 2 , 1}
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using i64 = long long;
const i64 P = 1e9 + 7;

i64 mul(i64 a, i64 b) {
    return (a * b) % P;
}

int main() {
    int n, max_val;
    std::cin >> n >> max_val; // max_val is the largest value expected in array 'a'

    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    const i64 X = rng() % (P - 2) + 2;

    // Precompute powers up to max_val
    std::vector<i64> p(max_val + 1);
    p[0] = 1;
    for (int i = 1; i <= max_val; i++) {
        p[i] = mul(p[i - 1], X);
    }

    i64 set_hash = 0;
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        set_hash = (set_hash + p[val]) % P;
    }

    std::cout << set_hash << "\n";
    return 0;
}

// The below code is the real polynomial hashing (Needs modulus)
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using i64 = long long;
const i64 P = 1e9 + 7; // Or another large prime

i64 mul(i64 a, i64 b) {
    return (a * b) % P;
}

int main() {
    int n;
    std::cin >> n;

    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    const i64 X = rng() % (P - 2) + 2; // Random base in range [2, P-1]

    std::vector<i64> p(n);
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = mul(p[i - 1], X);
    }

    std::vector<int> a(n);
    i64 hash_val = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        // Hash depends on BOTH value a[i] and position i
        hash_val = (hash_val + mul(a[i], p[n - 1 - i])) % P;
    }

    std::cout << hash_val << "\n";
    return 0;
}
