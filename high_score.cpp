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

const ll INF = numeric_limits<ll>::max();

int n, m;
vector<tuple<int, int, ll>> edges;
vector<vector<int>> adj;
vector<bool> visited;
vector<ll> dist;

bool dfs(int u) {
    if (u == n - 1) return true;
    visited[u] = true;
    for (int& v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v)) return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;

    adj.resize(n);
    dist.resize(n, INF);
    visited.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({u, v, -w});
        adj[u].push_back(v);
    }

    dist[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool changed = false;
        for (auto& [u, v, w] : edges) {
            if (dist[u] == INF) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }
        if (!changed) break;
    }

    for (auto& [u, v, w] : edges) {
        if (dist[u] == INF) continue;
        if (dist[v] > dist[u] + w) {
            visited.assign(n, false);
            if (dfs(u)) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << -dist[n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}