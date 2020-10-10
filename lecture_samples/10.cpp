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
};

int main() {
    return 0;
}