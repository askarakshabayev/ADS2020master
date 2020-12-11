#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;
ll sz, n;
ll tree[4000000];
ll a[1000000];
ll inf = 1e14;

void init(ll n) {
    sz = 1;
    while (sz < n) sz *= 2;
}

void build(ll *a, ll n, ll x, ll lx, ll rx) {
    if (rx - lx == 1) { // lx .. rx - 1
        if (lx < n)
            tree[x] = a[lx];
    } else {
        ll m = (lx + rx) / 2;
        build(a, n, 2 * x + 1, lx, m);
        build(a, n, 2 * x + 2, m, rx);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }
}

void build(ll *a, ll n) {
    init(n);
    build(a, n, 0, 0, sz);
}


int mini(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r)
        return inf;
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
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    build(a, n);
    ll sum = 0ll;
    for (ll i = 0; i < m; i++) {
        ll l, r;
        cin >> l >> r;
        sum += (ll)mini(l - 1, r - 1);
    }

    cout << sum;
    return 0;
}
