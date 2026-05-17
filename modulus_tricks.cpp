constexpr int P = 1000000007;
int norm(int x) {
    if (x < 0)  x += P;
    if (x >= P) x -= P;
    return x;
}
// Normalizes x to the range [0, P). Handles one step of over/underflow — assumes input is in (-P, 2P).
