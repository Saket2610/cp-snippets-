// Computes the prefix function pi (or failure function) for string s.
// pi[i] is the length of the longest proper prefix of s[0...i] 
// that is also a suffix of s[0...i].

// p[0] = 0 
// s = "abacaba"
// i = 5 ("abacab"):
// Substring ends with "ab". Matches prefix "ab" (length 2) -> p[5]=2
// p = {0 , 0 , 1 , 0 , 1 , 2 , 3}
// z = {7 , 0 , 1 , 0 , 3 , 0 , 1}
std::vector<int> computePrefixFunction(const std::string& s) {
    int n = s.size();
    std::vector<int> pi(n, 0);
    
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    
    return pi;
}
