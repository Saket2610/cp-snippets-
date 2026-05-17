#include <array>

// Returns {gcd, x, y} such that a*x + b*y = gcd(a, b)
std::array<int, 3> exgcd(int a, int b) {
    if (b == 0)
        return {a, 1, 0};
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}
// input a , b 
// output ax + by = gcd(a,b);
// --- Usage examples ---

// 1. Just get the GCD
int g = exgcd(30, 20)[0];       // g = 10

// 2. Get all three values
auto [g, x, y] = exgcd(30, 20);
// g=10, x=1, y=-1  →  30*1 + 20*(-1) = 10 ✓

// 3. Modular inverse of a mod m  (only valid when gcd(a, m) == 1)
auto [g, inv, _] = exgcd(a, m);
int mod_inv = (inv % m + m) % m;   // always positive
