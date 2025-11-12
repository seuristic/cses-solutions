#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define ll long long
#define size(x) (int)(x).size()

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    pair<int, int> a, b;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                a = {i, j};
                q.push(a);
            } else if (grid[i][j] == 'B') {
                b = {i, j};
            }
        }
    }

    vector<vector<int>> arrive(n, vector<int>(m, -1));
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && arrive[nr][nc] == -1) {
                arrive[nr][nc] = i;
                q.push({nr, nc});
            }
        }
    }

    if (arrive[b.first][b.second] == -1) {
        cout << "NO" << endl;
    } else {
        string dir = "URDL";
        string result = "";
        int r = b.first, c = b.second;
        while (r != a.first || c != a.second) {
            int i = arrive[r][c];
            result += dir[i];
            r -= dr[i];
            c -= dc[i];
        }
        reverse(result.begin(), result.end());
        cout << "YES" << endl;
        cout << size(result) << endl;
        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}