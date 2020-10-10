#include <iostream>
#include <queue>

using namespace std;
int dx[8] = {2,  2, -2, -2, 1,  1, -1, -1};
int dy[8] = {1, -1,  1, -1, 2, -2,  2, -2};
int a[9][9];
int x1, y1, x2, y2;

bool ok(int x, int y) {
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    queue<pair<int, int> > q;

    a[x1][y1] = 1; // a[i][j] > 0
    q.push(make_pair(x1, y1));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        for (int i = 0; i < 8; i++) {
            if (ok(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 0) {
                q.push(make_pair(x + dx[i], y + dy[i]));
                a[x + dx[i]][y + dy[i]] = a[x][y] + 1;
            }
        }
        q.pop();
    }

    // for (int i = 1; i <= 8; i++) {
    //     for (int j = 1; j <= 8; j++) 
    //         cout << a[i][j] << " ";
    //     cout << endl;
    // }
    cout << a[x2][y2] - 1;
    return 0;
}