struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }

    // to add at index x 
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    // find sum from 0 to i 
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    // Finds the smallest index where prefix sum ≥ k.
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};
 
struct Max {
    int x = -1E9;
    Max &operator+=(Max a) {
        x = std::max(x, a.x);
        return *this;
    }
};

// to store maximum till index i 
 Fenwick<Max> fen(val.size());


// to store minimum till index i /// also change all max to min in struct // same cases 
Fenwick<Min> fen(val.size());

// to store sum till index i 

Fenwick<int> fen(val.size());  // just use int directly
