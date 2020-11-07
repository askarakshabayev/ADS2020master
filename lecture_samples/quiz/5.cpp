#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int a[1000000];

void bst(int l, int r) {
    if (l > r)
        return;
    int m = (l + r) / 2;
    cout << a[m] << " ";
    bst(l, m - 1);
    bst(m + 1, r);
}

int main() {
    int n;
    cin >> n;
    n = pow(2, n) - 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    bst(0, n - 1);
    return 0;
}