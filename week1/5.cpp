#include <iostream>

using namespace std;

int a[1000];
int n, m, x;

bool find(int x) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x)
            return true;
        if (a[m] > x)
            r = m - 1; // l .. m - 1
        else 
            l = m + 1; // m + 1 .. r
    }
    return false;
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++) {
        cin >> x;
        if (find(x))
            cout << "YES\n";
        else
            cout << "NO\n";        

    }

    return 0;
}