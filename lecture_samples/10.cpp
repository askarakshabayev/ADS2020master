#include <iostream>
#include <vector>

using namespace std;

class SegTree {
    public:
    vector<long long> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size - 1, 0);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) 
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];        
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) { 
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int min(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r)
            return 0;
    }
    int min(int l, int r) {
        return min(l, r, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r)
            return 0;
        else if (lx >= l && rx <= r)
            return tree[x];
        else {
            int m = (lx + rx) / 2;
            long long s1 = sum(l, r, 2 * x + 1, lx, m);
            long long s2 = sum(l, r, 2 * x + 2, m, rx);
            return s1 + s2;
        }
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

class SegTree {
    public:
    vector<long long> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size - 1, 0);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];         
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
};

int main() {
    
    return 0;
}