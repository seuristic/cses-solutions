#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

int n, m;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> path, deg;

void dfs(int u) {
    while (!adj[u].empty()) {
        auto [v, index] = adj[u].back();
        adj[u].pop_back();
        if (visited[index]) continue;
        visited[index] = true;
        dfs(v);
    }
    path.push_back(u);
}

void solve() {
    cin >> n >> m;

    adj.assign(n, {});
    visited.assign(m, false);
    deg.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        ++deg[u];
        ++deg[v];
    }

    for (int i = 0; i < n; ++i) {
        if (deg[i] % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    dfs(0);

    if (sz(path) != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int p : path) {
        cout << p + 1 << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}