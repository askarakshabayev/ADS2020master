#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll p_pow[100];

void init_p(int n) {
    ll p = 31;
    p_pow[0] = 1;
    for (int i = 1; i <= n; i++)
        p_pow[i] = p_pow[i - 1] * p;
}

vector<ll> hash_(string s) {
    vector<ll> h(s.size());
    h[0] = s[0];
    for (int i = 1; i < s.size(); i++)
        h[i] = h[i - 1] + s[i] * p_pow[i];
    return h;
}

ll hash_string(string s) {
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] * p_pow[i];
    return sum;
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    init_p(s.size());

    vector<ll> h = hash_(s);
    ll hash_t = hash_string(t);

    for (int i = 0; i + m - 1 < n; i++) {
        int j = i + m - 1;
        ll hash_i_j = h[j];
        if (i) hash_i_j -= h[i - 1];
        if (hash_t * p_pow[i] == hash_i_j)
            cout << i << " ";
    }

    return 0;
}