#include <iostream>
#include <vector>

using namespace std;
vector<int> g[100];
int u[100]; // u[i] = 0, u[i] = 1, u[i] = 2

int n, m, x, y;
bool ok = true;

void dfs(int v, int c) {
    u[v] = c;
    for (int i = 0; i < g[v].size(); i++) {
        int j = g[v][i];
        if (u[j] == 0) {
            dfs(j, 3 - c);
        } else if (u[j] == c){
            ok = false;
        }
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
    for (int i = 0; i < n; i++)
        if (u[i] == 0)
            dfs(i, 1);
    if (ok)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;

}