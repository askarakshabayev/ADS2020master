#include <iostream>
#include <vector>

using namespace std;

int find_lower(vector<int> &a, int x) {
    int l = -1;
    int r = a.size();
    while (l + 1 < r) {
        cout << l << " " << r << endl;
        int m = (l + r) / 2;
        if (a[m] <= x)
            l = m;
        else
            r = m;        
    }
    return l;
}

int find_upper(vector<int> &a, int x) {
    int l = -1;
    int r = a.size();
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
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;
    int ind = find_upper(a, x);
    cout << ind;
    return 0;
}