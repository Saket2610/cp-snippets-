string s;
cin >> s;
int n = s.size();
vector<int> a(n);
for (int i = 0; i < n; i++) {
    a[i] = std::string("ANOT").find(s[i]);
    // s[i] = "A" then a[i] = 0;
    // s[j] = "N" then a[j] = 1
}

// suffix table 
// 4 = number of unique elements in the string 
// um[x][i] = how many times character x appears from index i to end of string.
std::vector sum(4, std::vector<int>(n + 1));
for (int x = 0; x < 4; x++) {
    for (int i = n - 1; i >= 0; i--) {
        sum[x][i] = sum[x][i + 1] + (a[i] == x);
    }
}
