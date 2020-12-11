#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> g[100];
int u[100]; // u[i] = 1 -> queue
int d[100]; // d[i] = min distance between x and i
queue<int> q;

int n, m, x, y;

void bfs(int x) {
    u[x] = 1;
    d[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int v = q.front();
        for (int i = 0; i < g[v].size(); i++) {
            if (u[g[v][i]] == 0) {
                q.push(g[v][i]);
                u[g[v][i]] = 1;
                d[g[v][i]] = d[v] + 1;
            }
        }
        q.pop();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // cin >> x;
    // bfs(--x);
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (u[i] == 0) {
            bfs(i);
            cnt++;
        }
    cout << cnt;
    return 0;
}