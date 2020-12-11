#include <iostream>
#include <vector>

using namespace std;
vector<int> g[100];
int n, m, x, y;

class E {
    public:
    int x, y, l;
    E(int x, int y, int l) {
        this->x = x;
        this->y = y;
        this->l = l;
    }
};

E g1[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
        // g1[i].x = x;
        // g1[i].y = y;
        // g1[i].l = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " -- ";
        for (int j = 0; j < g[i].size(); j++)
            cout << g[i][j] + 1 << " ";
        cout << endl;
    }

    return 0;
}