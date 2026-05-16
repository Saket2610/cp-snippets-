struct node {
    node *child[2];
    node(){ child[0] = child[1] = NULL; }
};
// Inserts integer x into the trie, bit by bit from bit 31 down to bit 0.
void insert(node *trie, int x, int ind) {
    if(ind < 0) return;
    int k = (x >> ind) & 1;       // get ind-th bit of x
    if(!trie->child[k])
        trie->child[k] = new node;
    insert(trie->child[k], x, ind-1);
}
int p; // global variable storing the result

// Given x, finds the number already in the trie that maximizes XOR with x.
void find(node *trie, int x, int ind) {
    if(ind < 0) return;
    int k = (x >> ind) & 1;
    k ^= 1;                        // prefer the OPPOSITE bit (maximize XOR)
    if(!trie->child[k]) k ^= 1;   // if opposite not available, take same
    p = p << 1 | k;                // build the result bit by bit
    find(trie->child[k], x, ind-1);
}

// For each group, use a trie to find any one valid pair (XOR ≥ k),
// add both to answer and stop, or if no pair exists add just one representative 
// that will automatically pair validly with elements from other groups.
  
void get(vector<int> &v, int k, int pref) {
    node *trie = new node;
    int n = sz(v);

    rep(i, 0, n) {
        if(i) {
            find(trie, v[i], 31);         // find best XOR partner in trie
            if((p ^ v[i]) >= k) {         // if XOR >= k, we found a valid pair
                ans.pb(p + pref);         // reconstruct full value
                ans.pb(v[i] + pref);
                return;                   // only need ONE valid pair per group
            }
        }
        insert(trie, v[i], 31);           // insert current into trie
    }
    ans.pb(v[0] + pref);                  // no valid pair: add a "representative"
}
// get(x.sc,k,x.fr);
