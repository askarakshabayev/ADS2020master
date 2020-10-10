#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int used[100]; // used[i] = 0
int c[100];

int main() {
    queue<pair<int, int> > q;
    int a, b, x, d;
    cin >> a >> b;
    q.push(make_pair(a, 0));
    used[a] = 1;
    c[a] = a;

    while (!q.empty()) {
        x = q.front().first; // x + 1, x * 2, x - 1, x / 2
        d = q.front().second;

        if (x == b) {
            break;
        }

        if (used[x + 1] == 0) {
            used[x + 1] = 1;
            q.push(make_pair(x + 1, d + 1));
            c[x + 1] = x;
        }

        if (used[x * 2] == 0) {
            used[x * 2] = 1;
            q.push(make_pair(x * 2, d + 1));
            c[x * 2] = x;
        }

        if (used[x / 2] == 0) {
            used[x / 2] = 1;
            q.push(make_pair(x / 2, d + 1));
            c[x / 2] = x;
        }

        if (x - 1 >= 0 && used[x - 1] == 0) {
            used[x - 1] = 1;
            q.push(make_pair(x - 1, d + 1));
            c[x - 1] = x;
        }
        q.pop();
    }
    cout << d << endl;
    vector<int> result;
    result.push_back(b); // 12 6 3 2 
    while (c[b] != b) {
        b = c[b]; // b = 3
        result.push_back(b);
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    return 0;
}