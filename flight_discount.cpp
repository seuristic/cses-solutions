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

// APPROACH 1: 2 Dijkstra's Algorithm
// int n, m;
// vector<vector<pair<int, ll>>> g, rev_g;
// vector<ll> dist_from_start, dist_to_end;
// vector<tuple<int, int, ll>> edges;

// void dijkstra(int u, vector<vector<pair<int, ll>>>& g, vector<ll>& dist) {
//     priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
//     q.push({0, u});
//     dist[u] = 0;
//     while (!q.empty()) {
//         auto [d, u] = q.top();
//         q.pop();
//         if (d != dist[u]) continue;
//         for (auto& [v, w] : g[u]) {
//             if (dist[u] == INF) continue;
//             if (dist[v] > dist[u] + w) {
//                 dist[v] = dist[u] + w;
//                 q.push({dist[v], v});
//             }
//         }
//     }
// }

// void solve() {
//     cin >> n >> m;

//     g.resize(n);
//     rev_g.resize(n);
//     dist_from_start.resize(n, INF);
//     dist_to_end.resize(n, INF);

//     for (int i = 0; i < m; ++i) {
//         int a, b;
//         ll c;
//         cin >> a >> b >> c;
//         --a, --b;
//         edges.push_back({a, b, c});
//         g[a].push_back({b, c});
//         rev_g[b].push_back({a, c});
//     }

//     dijkstra(0, g, dist_from_start);
//     dijkstra(n - 1, rev_g, dist_to_end);

//     ll result = INF;
//     for (auto& [u, v, w] : edges) {
//         if (dist_from_start[u] == INF || dist_to_end[v] == INF) continue;
//         result = min(result, dist_from_start[u] + (w / 2) + dist_to_end[v]);
//     }

//     cout << result << endl;
// }

// APPROACH 2: 2-layer graph + Dijkstra's on this graph
int n, m;
vector<vector<pair<int, ll>>> adj;
vector<ll> dist;

void solve() {
    cin >> n >> m;

    adj.resize(2 * n);
    dist.resize(2 * n, INF);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c});
        adj[a].push_back({n + b, c / 2});
        adj[n + a].push_back({n + b, c});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, 0});
    dist[0] = 0;
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] == INF) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }

    cout << dist.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}