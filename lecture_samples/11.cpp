#include <iostream>
#include <vector>

using namespace std;

class SegTree {
    public:
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign( 2 * size - 1, 0);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size())
                tree[x] = a[lx];
        } else {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    void build(vector<int> &a) {
        init(a.size());
        build(a, 0, 0, size);
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
        {
            set(i, v, 2 * x + 2, m, rx);
        }

        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int mini (int l, int r, int x, int lx, int rx) {
        cout << l << " " << r << " " << x << " " << l << " " << rx << endl;
        if (l >= rx || lx >= r) 
            return 100000;

        if (lx >= l && rx <= r)
            return tree[x];
        
        int m = (lx + rx) / 2;
        int mini1 = mini(l, r, 2 * x + 1, lx, m);
        int mini2 = mini(l, r, 2 * x + 2, m, rx);

        return min(mini1, mini2);
    }
    int mini(int l, int r) {
        return mini(l, r, 0, 0, size);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    SegTree st;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    st.build(a);

    // for (int i = 0; i < st.size * 2 - 1; i++)
    //     cout << st.tree[i] << " ";
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            int p, v;
            cin >> p >> v;
            st.set(p, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.mini(l, r) << endl;
        }
    }
    return 0;
}