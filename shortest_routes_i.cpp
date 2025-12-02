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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    vector<ll> dist(n, INF);

    q.push({0, 0});
    dist[0] = 0;

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (d > dist[u]) continue;

        for (const auto& [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }

    for (const ll& d : dist) {
        cout << d << ' ';
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