// The segment tree is initialized to all zeros by default
// A build() function is needed when you have pre-existing data to load into the tree

class SegmentTree {
private:
    int n;
    std::vector<int> mx, lazy;
    void add(int p, int v) {
        mx[p] += v;
        lazy[p] += v;
    }
    void push(int p) {
        add(2 * p, lazy[p]);
        add(2 * p + 1, lazy[p]);
        lazy[p] = 0;
    }
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y)
            return add(p, v);
        int m = (l + r) / 2;
        push(p);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        mx[p] = std::max(mx[2 * p], mx[2 * p + 1]);
    }
    int rangeMax(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x)
            return 0;
        if (l >= x && r <= y)
            return mx[p];
        int m = (l + r) / 2;
        push(p);
        return std::max(rangeMax(2 * p, l, m, x, y), rangeMax(2 * p + 1, m, r, x, y));
    }
public:
    SegmentTree(int n) : n(n), mx(4 * n), lazy(4 * n) {}
    void rangeAdd(int l, int r, int v) {
        rangeAdd(1, 0, n, l, r, v);
    }
    int rangeMax(int l, int r) {
        return rangeMax(1, 0, n, l, r);
    }
};
 
