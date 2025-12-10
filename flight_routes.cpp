#include <algorithm>
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

#define ll long long
#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

const ll INF = LLONG_MAX;

// void solve() {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<vector<pair<int, ll>>> adj(n);
//     for (int i = 0; i < m; ++i) {
//         int u, v;
//         ll w;
//         cin >> u >> v >> w;
//         --u, --v;
//         adj[u].push_back({v, w});
//     }

//     vector<priority_queue<ll>> dist(n, priority_queue<ll>());
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < k; ++j) {
//             dist[i].push(INF);
//         }
//     }

//     priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

//     q.push({0, 0});
//     dist[0].pop();
//     dist[0].push(0);

//     while (!q.empty()) {
//         auto [d, u] = q.top();
//         q.pop();

//         if (d > dist[u].top()) continue;

//         for (auto [v, w] : adj[u]) {
//             ll newDist = d + w;
//             if (newDist < dist[v].top()) {
//                 dist[v].pop();
//                 dist[v].push(newDist);
//                 q.push({newDist, v});
//             }
//         }
//     }

//     vector<ll> result;
//     while (!dist[n - 1].empty()) {
//         result.push_back(dist[n - 1].top());
//         dist[n - 1].pop();
//     }

//     reverse(all(result));

//     for (ll x : result) {
//         cout << x << ' ';
//     }
//     cout << endl;
// }

// OPTIMIZED APPROACH
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    vector<ll> dist(k, INF);
    vector<int> visited(n, 0);

    q.push({0, 0});

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (visited[u] >= k) continue;

        if (u == n - 1) {
            dist[visited[u]] = d;
        }

        ++visited[u];
        for (auto [v, w] : adj[u]) {
            q.push({d + w, v});
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << dist[i] << ' ';
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