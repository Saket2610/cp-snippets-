// The segment tree is initialized to all zeros by default
// A build() function is needed when you have pre-existing data to load into the tree

int seg[4 * N], lazy[4 * N];

// This is the standard lazy propagation flush — before using a node, apply any pending additions.
void updlazy(int l, int r, int pos) {
    seg[pos] += lazy[pos];   // Apply pending lazy update to this node
    if (l == r) {
        lazy[pos] = 0;        // Leaf node: clear lazy and return
        return;
    }
    lazy[pos * 2]     += lazy[pos];   // Push lazy down to left child
    lazy[pos * 2 + 1] += lazy[pos];   // Push lazy down to right child
    lazy[pos] = 0;                     // Clear current node's lazy
}
// range update 
// pos = root of segment tree / 1 
void upd(int l, int r, int pos, int ql, int qr, int v) {
    if (lazy[pos] != 0) updlazy(l, r, pos);  // Flush lazy before doing anything

    if (l >= ql && r <= qr) {         // Current segment fully inside query range
        seg[pos] += v;                 // Add v to this node
        if (l != r) {
            lazy[pos * 2]     += v;    // Propagate lazily to children
            lazy[pos * 2 + 1] += v;
        }
        return;
    } else if (l > qr || r < ql) return;  // No overlap — do nothing

    int mid = (l + r) / 2;
    upd(l, mid,     pos*2,   ql, qr, v);   // Recurse left
    upd(mid+1, r,   pos*2+1, ql, qr, v);   // Recurse right
    seg[pos] = min(seg[pos*2], seg[pos*2+1]); // Update current node from children
}
 
int query(int l, int r, int pos, int ql, int qr) {
    if (lazy[pos] != 0) updlazy(l, r, pos);  // Flush lazy first
    if (l >= ql && r <= qr) return seg[pos]; // Fully inside: return this node's min
    else if (l > qr || r < ql) return INF;  // No overlap: return infinity

    int mid = (l + r) / 2;
    return min(
        query(l, mid,   pos*2,   ql, qr),   // Min of left half
        query(mid+1, r, pos*2+1, ql, qr)    // Min of right half
    );
}
