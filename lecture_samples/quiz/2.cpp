#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_upper(vector<int> &a, int x) {
    int n = a.size();
    int l = -1;
    int r = n;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] >= x)
            r = m;
        else 
            l = m;
    }
    return r;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        cout << a[find_upper(a, x)] << endl;
    }

    return 0;
}