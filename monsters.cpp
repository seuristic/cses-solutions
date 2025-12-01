#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
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
#define all(x) begin(x), end(x)

const int dir[] = {0, -1, 0, 1, 0};

int n, m;
vector<string> grid;
vector<vector<int>> distM, distA, parent;
pair<int, int> A;
int closestDist = INT_MAX, closestR = -1, closestC = -1;

void bfs(queue<pair<int, int>>& q, vector<vector<int>>& dist) {
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir[i];
            int nc = c + dir[i + 1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && dist[nr][nc] > dist[r][c] + 1) {
                dist[nr][nc] = dist[r][c] + 1;
                parent[nr][nc] = i;
                q.push({nr, nc});
            }
        }
    }
}

void check(int r, int c) {
    if (grid[r][c] != '#' && distM[r][c] > distA[r][c] && closestDist > distA[r][c]) {
        closestDist = distA[r][c];
        closestR = r;
        closestC = c;
    }
}

void solve() {
    cin >> n >> m;
    grid.resize(n);
    for (string& row : grid) {
        cin >> row;
    }

    distM.resize(n, vector<int>(m, INT_MAX));
    distA.resize(n, vector<int>(m, INT_MAX));
    parent.resize(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == 'M') {
                distM[r][c] = 0;
                q.push({r, c});
            } else if (grid[r][c] == 'A') {
                A = {r, c};
                distA[r][c] = 0;
            }
        }
    }

    bfs(q, distM);
    q.push(A);
    bfs(q, distA);

    for (int r = 0; r < n; ++r) {
        check(r, 0);
        check(r, m - 1);
    }
    for (int c = 0; c < m; ++c) {
        check(0, c);
        check(n - 1, c);
    }

    if (closestDist == INT_MAX) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << closestDist << endl;
        string result = "";
        while (closestR != A.first || closestC != A.second) {
            int i = parent[closestR][closestC];
            result += "LURD"[i];
            closestR -= dir[i];
            closestC -= dir[i + 1];
        }
        reverse(all(result));
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