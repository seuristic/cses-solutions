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
#define all(x) begin(x), end(x)

bool dfs(int u, int p, const vector<vector<int>>& adj, vector<int>& visited, vector<int>& parent) {
    visited[u] = 1;

    for (int v : adj[u]) {
        if (v == p) continue;
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v, u, adj, visited, parent)) return true;
        } else {
            vector<int> cycle{v};
            int curr = u;
            while (curr != v) {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(v);
            reverse(all(cycle));
            cout << size(cycle) << endl;
            for (int x : cycle) {
                cout << x << ' ';
            }
            cout << endl;
            return true;
        }
    }

    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n + 1, 0), parent(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        if (dfs(i, -1, adj, visited, parent)) {
            return;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}