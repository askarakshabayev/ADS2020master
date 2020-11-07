#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int sz, n;
vector<long long> tree;
vector<int> a(1000000);


void init(int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    tree.assign(2 * sz - 1, 0);
}

void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) { // lx .. rx - 1
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
    build(a, 0, 0, sz);
}


int mini(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r)
        return INT_MAX;
    if (lx >= l && rx <= r)
        return tree[x];
    int m = (lx + rx) / 2;
    int mini1 = mini(l, r, 2 * x + 1, lx, m);
    int mini2 = mini(l, r, 2 * x + 2, m, rx);
    return min(mini1, mini2);
}

int mini(int l, int r) {
    return mini(l, r, 0, 0, sz);
}

int main() {
    int n, m;
    cin >> n >> m; 
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(a);
    long long sum = 0ll;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        sum += (long long)mini(l - 1, r - 1);
    }

    cout << sum;
    return 0;
}