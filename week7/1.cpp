#include <iostream>
#define ll long long 

using namespace std;

ll hash_(string s) {
    ll p = 31;
    ll p_pow = 1;
    ll sum = 0;
    for (int i = 0; i < s.size(); i++) { // i = 0, 1
        sum += s[i] * p_pow;            // s[0] * p^0 + s[1] * p^1 ... s[n - 1] * p^(n - 1) 
        p_pow *= p;
    }
    return sum;
}

int main() {
    string s;
    cin >> s;
    cout << hash_(s);
    return 0;
}