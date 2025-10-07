#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
#define fastIO() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool dfs(int r, int c, vector<string> &grid, vector<vector<bool>> &visited, const int &n, const int &m) {
    if (grid[r][c] == '#' || visited[r][c]) return false;

    visited[r][c] = true;

    int dir[] = { 0, -1, 0, 1, 0 };
    bool possible = true;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dir[i];
        int nc = c + dir[i + 1];
        if (nr >= 0 && nr < n && nc >=0 && nc < m && grid[nr][nc] != '#' && !visited[nr][nc]) {
            dfs(nr, nc, grid, visited, n, m);
        }
    }

    return possible;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string &row : grid) {
        cin >> row;
    }

    int result = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dfs(i, j, grid, visited, n, m)) {
                ++result;
            }
        }
    }

    cout << result << endl;
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
