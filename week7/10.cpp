#include <iostream>
#include <vector>

using namespace std;
vector<int> g[100];
bool u[100]; 

int n, m, x, y;

void dfs(int v) {
    cout << v + 1 << " ";
    u[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int j = g[v][i];
        if (!u[j]) 
            dfs(j);
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
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (!u[i]) {
            dfs(i);
            cnt++;
        }
    cout << cnt;
    return 0;
}