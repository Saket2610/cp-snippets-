
std::vector<int> Z(std::string s) {
    int n = s.size();
    std::vector<int> z(n + 1);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++) {
        z[i] = std::max(0, std::min(j + z[j] - i, z[i - j]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > j + z[j]) {
            j = i;
        }
    }
    return z;
}
auto z = Z(s);
// z[i] = length of the longest prefix of s
       // that matches the substring starting at i

// z[0] = n
// index: 0 1 2 3 4 5 6
// char : a a a b a a b
// z    : 7 2 1 0 3 1 0
