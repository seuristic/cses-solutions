#include <algorithm>
#include <bitset>
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

const int N = 2501;
int n, m;
vector<tuple<int, int, ll>> edges;
vector<vector<int>> adj, rev_adj;
vector<bool> visited;
vector<ll> dist;

// bool dfs(int u) {
//     if (u == n - 1) return true;
//     visited[u] = true;
//     for (int& v : adj[u]) {
//         if (!visited[v]) {
//             if (dfs(v)) return true;
//         }
//     }
//     return false;
// }

bitset<N> bfs(int u, vector<vector<int>>& adj) {
    bitset<N> visited;
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return visited;
}

void solve() {
    cin >> n >> m;

    adj.resize(n);
    rev_adj.resize(n);
    dist.resize(n, INF);
    visited.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({u, v, -w});
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    dist[0] = 0;

    // ALTERNATE APPROACH
    // for (int i = 0; i < n; ++i) {
    //     for (auto& [u, v, w] : edges) {
    //         if (dist[u] == INF) continue;
    //         ll newDist = min(dist[v], dist[u] + w);
    //         if (i == n - 1 && dist[v] > newDist) {
    //             visited.assign(n, false);
    //             if (dfs(u)) {
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }
    //         dist[v] = newDist;
    //     }
    // }

    auto included = bfs(0, adj) & bfs(n - 1, rev_adj);
    for (int i = 0; i < n; ++i) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] == INF) continue;
            if (!included[u] || !included[v]) continue;
            ll newDist = min(dist[v], dist[u] + w);
            if (i == n - 1 && dist[v] > newDist) {
                cout << -1 << endl;
                return;
            }
            dist[v] = newDist;
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