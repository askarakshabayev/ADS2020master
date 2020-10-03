#include <iostream>

using namespace std;
int a, b, n;

bool f(int x) {
    int t1 = x / a;
    int t2 = x / b;
    return (t1 * t2 >= n);
}

int main() {
    cin >> a >> b >> n;
    int l = 0;
    int r = 1e4;

    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (f(m))
            r = m;
        else 
            l = m;
    }
    cout << r;
    return 0;
}