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
#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

int n, m;
vector<vector<int>> adj;
vector<int> visited, parent, cycle;

bool dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (visited[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (visited[v] == 1) {
            cycle.push_back(v);
            int curr = u;
            while (curr != v) {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(v);
            reverse(all(cycle));
            return true;
        }
    }
    visited[u] = 2;
    return false;
}

void solve() {
    cin >> n >> m;

    adj.assign(n, {});
    visited.assign(n, 0);
    parent.assign(n, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
    }

    for (int u = 0; u < n; ++u) {
        if (visited[u] == 0 && dfs(u)) {
            break;
        }
    }

    if (size(cycle) == 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << size(cycle) << endl;
        for (int& node : cycle) {
            cout << node + 1 << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}